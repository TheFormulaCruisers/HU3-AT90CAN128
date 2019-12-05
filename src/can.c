#include <avr/io.h>
#include <avr/interrupt.h>
#include <can.h>

void can_init(void) {
	
	// Reset CAN controller
	CANGCON = _BV(SWRES);
	
	// Set CAN timing bits
	CANBT1 = 0x02;
	CANBT2 = 0x04;
	CANBT3 = 0x13;
	
	// Enable interrupt(s)
	CANIE2 = _BV(IEMOB0);
	CANGIE = _BV(ENIT) | _BV(ENTX);

	// Initialize MObs
	// CAN revision 2.0A
	uint8_t dat_i;
	for (dat_i = 0; dat_i < 14; dat_i++) {
		CANPAGE = dat_i << 4;
		CANSTMOB = 0x00;
		CANCDMOB = 0x00;
		CANIDM = 0xFFFFFFFF;
		CANIDT = 0x00000000;
	}

	// Enable CAN controller
	CANGCON = _BV(ENASTB);
}

void can_filter(uint8_t id) {
    
	uint8_t dat_i;
	for (dat_i = 1; dat_i < 14; dat_i++) {

		// Select MOb[i]
		CANPAGE = dat_i << 4;

		// Use MOb[i] if its id is zero (i.e. not yet set)
		if (CANIDT1 == 0x00) {
			CANIDT1 = id;
			CANCDMOB = _BV(CONMOB1);
			break;
		}
	}
}

void can_receive(uint8_t *id, uint8_t *dat, uint8_t *len) {

	uint8_t mob_i;
	for (mob_i = 1; mob_i < 14; mob_i++) {

		// Select MOb[i]
		CANPAGE = (0xF0 & mob_i << 4);

		// Read MOb[i] if its reception bit has been set
		if (CANSTMOB & _BV(RXOK)) {

			// Get id
			*id = CANIDT1;

			// Get message length
			*len = CANCDMOB & 0x0F;

			// Get message
			uint8_t dat_i;
			for (dat_i = 0; dat_i < *len; dat_i++) {
				*(dat+dat_i) = CANMSG;
			}

			// Reset reception bit
			// TODO: CANCDMOB/CONMOB needed to re-enable reception?
			CANSTMOB &= ~_BV(RXOK);
			break;
		}
	}
}

void can_send(uint8_t *dat, uint8_t len) {

	// Select MOb0
	CANPAGE = 0x00;

	// Set message
	uint8_t dat_i;
	for (dat_i = 0; dat_i < len; dat_i++) {
		CANMSG = *(dat+dat_i);
	}

	// Set message length and start transmission
	CANCDMOB = (CANCDMOB & _BV(IDE)) | _BV(CONMOB0) | (len & 0x0F);
}

ISR(CANIT_vect) {
	
	// Store CANPAGE
	uint8_t page_buf = CANPAGE;

	// Select MOb0
	CANPAGE = 0x00;
	
	// Respond to TXOK flag
	if (CANSTMOB & _BV(TXOK)) {
		//
	}
	
	// Clear interrupt flags
	CANSTMOB = 0x00;
	
	// Restore CANPAGE
	CANPAGE = page_buf;
}