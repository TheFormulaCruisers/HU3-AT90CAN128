#ifndef _NODE6_C
#define _NODE6_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node6_msk = 32;
volatile uint8_t node6_reg = 32;

void node6_init(void *msg, uint8_t msg_size) {
	DDRC |= node6_msk;
	PORTC = node6_msk | (PORTC & ~node6_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node6_receive(void *msg, uint8_t msg_size) {
	node6_reg ^= node6_msk;
	PORTC = node6_reg | (PORTC & ~node6_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif