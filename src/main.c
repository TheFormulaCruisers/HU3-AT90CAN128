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

int main (void) {
	
	can_init();
	can_filter(0);
	sei();

	uint8_t dat[2] = {0x50, 0x50};
	can_transmit(dat, 2);
	
	const uint32_t duration = 1000000;
	uint32_t ledi;
	uint8_t leds = 0x01;
	uint8_t dir = 0;
	DDRC = 0xFF;
	while (1) {
		for (ledi = 0; ledi < duration; ledi++);
		if (leds == 0x80) {
			dir = 1;
		} else if (leds == 0x01) {
			dir = 0;
		}
		if (dir) {
			leds >>= 1;
		} else {
			leds <<= 1;
		}
		PORTC = leds;
	}

	while(1);
	return 0;
}