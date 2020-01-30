#ifndef _NODE1_C
#define _NODE1_C

#include <avr/io.h>
#include <logger.h>

volatile const uint8_t node1_msk = 1;
volatile uint8_t node1_reg = 1;

void node1_init(void *msg, uint8_t msg_size) {
	DDRC |= node1_msk;
	PORTC = node1_msk | (PORTC & ~node1_msk);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}

void node1_receive(void *msg, uint8_t msg_size) {
	node1_reg ^= node1_msk;
	PORTC = node1_reg | (PORTC & ~node1_msk);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}

#endif