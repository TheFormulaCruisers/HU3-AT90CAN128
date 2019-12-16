#include <avr/io.h>
#include <avr/interrupt.h>

#include <can.h>
#include <logger.h>
#include <nodeman.h>
#include <spi.h>

int can_test_rx(void) {
	
	can_init(0);
	can_filter(0);
	sei();

	DDRC = 0xFF;
	PORTC = 0x00;
	
	uint16_t id;
	uint8_t dat[8];
	uint8_t len;
	
	while(1) {
		CANPAGE = 0x10;
		while(!(CANSTMOB & _BV(RXOK)));
		can_receive(&id, dat, &len);
		PORTC = dat[0];
	}
	
	while(1);
	return 0;
}