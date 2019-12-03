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
	can_filter(1);

	uint8_t dat[4] = {1,2,3,4};
	uint8_t len = 4;
	can_send(dat, len);
	
	//uint8_t id;
	//can_receive(&id, dat, &len);

	while(1);
	return 0;
}