#ifndef _NODE2_C
#define _NODE2_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node2_msk = 2;
volatile uint8_t node2_reg = 2;

void node2_init(void *msg, uint8_t msg_size) {
	DDRC |= node2_msk;
	PORTC = node2_msk | (PORTC & ~node2_msk);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}

void node2_receive(void *msg, uint8_t msg_size) {
	node2_reg ^= node2_msk;
	PORTC = node2_reg | (PORTC & ~node2_msk);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}

#endif