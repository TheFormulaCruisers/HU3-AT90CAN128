#ifndef _NODE7_C
#define _NODE7_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node7_msk = 64;
volatile uint8_t node7_reg = 64;

void node7_init(void *msg, uint8_t msg_size) {
	DDRC |= node7_msk;
	PORTC = node7_msk | (PORTC & ~node7_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

void node7_receive(void *msg, uint8_t msg_size) {
	node7_reg ^= node7_msk;
	PORTC = node7_reg | (PORTC & ~node7_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

#endif