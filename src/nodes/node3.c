#ifndef _NODE3_C
#define _NODE3_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node3_msk = 4;
volatile uint8_t node3_reg = 4;

void node3_init(void *msg, uint8_t msg_size) {
	DDRC |= node3_msk;
	PORTC = node3_msk | (PORTC & ~node3_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node3_receive(void *msg, uint8_t msg_size) {
	node3_reg ^= node3_msk;
	PORTC = node3_reg | (PORTC & ~node3_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif