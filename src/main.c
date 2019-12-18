/*
  _  _ _   _    ____   ___ ____
 | || | | | |__|__ /  / __|__ /
 | __ | |_| |___|_ \ | (__ |_ \
 |_||_|\___/   |___/  \___|___/

*/

#include <avr/io.h>
#include <avr/interrupt.h>

#include <can.h>
#include <logger.h>
#include <nodeman.h>
#include <spi.h>

int main(void) {
	
	can_init(1);
	can_filter(0);
	sei();

	DDRC |= 0x30;
	PORTC |= 0x30;

	uint16_t id;
	uint8_t dat[8];
	uint8_t len;

	while(1) {
		CANPAGE = 0x10;
		while(!(CANSTMOB & _BV(RXOK)));
		can_receive(&id, dat, &len);
		PORTC |= dat[0] & 0x30;
	}

	return 0;
}