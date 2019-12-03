#include <avr/io.h>
#include <avr/interrupt.h>
#include <can.h>

void can_init(void) {
	
	// Set CAN timing bits
	CANBT1 = 0x02;
	CANBT2 = 0x04;
	CANBT3 = 0x13;

	// Enter enable mode
	CANGCON = _BV(ENASTB);

	// Configure MOb0
	// Mode: disable
	// IDE: CAN standard rev 2.0 A
	CANPAGE = 0x00;
	CANSTMOB = 0x00;
	CANCDMOB = 0x00;
	CANIDT = 0xF0000000;

	// Configure MOb1 to MOb14
	// Mode: receive
	uint8_t mob_i;
	for (mob_i = 1; mob_i < 14; mob_i++) {
		CANPAGE = (0xF0 & mob_i << 4) | (CANPAGE & 0x0F);
		CANSTMOB = 0x00;
		CANCDMOB = _BV(CONMOB1);
		CANIDT = 0x00000000;
		CANIDM = 0xFFFFFFFF;
	}
}

void can_filter(uint8_t id) {
    
	int mob_i;
	for (mob_i = 1; mob_i < 14; mob_i++) {

		// Select MOb[i]
		CANPAGE = (0xF0 & mob_i << 4) | (CANPAGE & 0x0F);

		// Use MOb[i] if its id is zero (i.e. not yet set)
		if (CANIDT1 == 0x00) {
			CANIDT1 = id;
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
			// TODO: CANCDMOB/CONMOB needed to reenable reception?
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
	CANCDMOB = _BV(CONMOB0) | (len & 0x0F);
	CANCDMOB = 0x00;
}