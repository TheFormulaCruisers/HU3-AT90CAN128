#ifndef _NODE4_C
#define _NODE4_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node4_msk = 8;
volatile uint8_t node4_reg = 8;

void node4_init(void *msg, uint8_t msg_size) {
	DDRC |= node4_msk;
	PORTC = node4_msk | (PORTC & ~node4_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node4_receive(void *msg, uint8_t msg_size) {
	node4_reg ^= node4_msk;
	PORTC = node4_reg | (PORTC & ~node4_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif