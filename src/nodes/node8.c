#ifndef _NODE8_C
#define _NODE8_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node8_msk = 128;
volatile uint8_t node8_reg = 128;

void node8_init(void *msg, uint8_t msg_size) {
	DDRC |= node8_msk;
	PORTC = node8_msk | (PORTC & ~node8_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node8_receive(void *msg, uint8_t msg_size) {
	node8_reg ^= node8_msk;
	PORTC = node8_reg | (PORTC & ~node8_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif