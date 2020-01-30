#ifndef _NODE5_C
#define _NODE5_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node5_msk = 16;
volatile uint8_t node5_reg = 16;

void node5_init(void *msg, uint8_t msg_size) {
	DDRC |= node5_msk;
	PORTC = node5_msk | (PORTC & ~node5_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node5_receive(void *msg, uint8_t msg_size) {
	node5_reg ^= node5_msk;
	PORTC = node5_reg | (PORTC & ~node5_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif