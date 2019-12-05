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
	sei();

	uint16_t i = 0;
	uint8_t dat[2];
	while (1) {
		dat[1] = i;
		dat[0] = i >> 8;
		can_send(dat, 2);
		i++;
	}

	while(1);
	return 0;
}