#include <avr/io.h>
#include <avr/interrupt.h>
#include <can.h>

// Convert an ID to the CAN revision 2.0A IDT-register format.
static uint32_t _id_to_idt_2a(uint16_t id) {
	return
		(uint32_t)(uint8_t)(id << 5) << 16 | 
		(uint32_t)(uint8_t)(id >> 3) << 24;
}

// Convert an ID to the CAN revision 2.0B IDT-register format.
static uint32_t _id_to_idt_2b(uint16_t id) {
	return
		(uint32_t)(uint8_t)(id << 3) | 
		(uint32_t)(uint8_t)(id >> 5) << 8 |
		(uint32_t)(uint8_t)(id >> 13) << 16;
}

void can_init(uint16_t txid) {

	// Reset CAN controller
	CANGCON = _BV(SWRES);

	// Set CAN timing bits
	CANBT1 = 0x02;
	CANBT2 = 0x04;
	CANBT3 = 0x13;

	// Enable interrupt(s)
	CANGIE = _BV(ENIT);

	// Initialize MOb0 (tx)
	CANPAGE = 0x00;
	CANSTMOB = 0x00;
	CANCDMOB = 0x00;
	CANIDM = 0xFFFFFFFF;
	CANIDT = _id_to_idt_2a(txid);

	// Initialize MOb1 to MOb14 (rx)
	uint8_t dat_i;
	for (dat_i = 1; dat_i < 14; dat_i++) {
		CANPAGE = dat_i << 4;
		CANSTMOB = 0x00;
		CANCDMOB = 0x00;
		CANIDM = 0xFFFFFFFF;
		CANIDT = 0x00000000;
	}

	// Enable CAN controller
	CANGCON = _BV(ENASTB);
}

void can_filter(uint16_t rxid) {
    
	uint8_t dat_i;
	for (dat_i = 1; dat_i < 14; dat_i++) {

		// Select MOb[i]
		CANPAGE = dat_i << 4;

		// Use MOb[i] if its id is zero (i.e. not yet set)
		if (CANIDT == 0x00000000) {
			CANIDT = _id_to_idt_2a(rxid);
			CANCDMOB = _BV(CONMOB1);
			break;
		}
	}
}

void can_receive(uint16_t *rxid, uint8_t *dat, uint8_t *len) {

	uint8_t mob_i;
	for (mob_i = 1; mob_i < 14; mob_i++) {

		// Select MOb[i]
		CANPAGE = mob_i << 4;

		// Read MOb[i] if its reception bit has been set
		if (CANSTMOB & _BV(RXOK)) {

			// Get id
			*rxid = CANIDT2 >> 5 | CANIDT1 << 3;

			// Get message length
			*len = CANCDMOB & 0x0F;

			// Get message
			uint8_t dat_i;
			for (dat_i = 0; dat_i < *len; dat_i++) {
				*(dat+dat_i) = CANMSG;
			}

			// Reset reception bit and re-enable reception
			CANSTMOB &= ~_BV(RXOK);
			CANCDMOB = _BV(CONMOB1);
			break;
		}
	}
}

void can_transmit(uint8_t *dat, uint8_t len) {

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