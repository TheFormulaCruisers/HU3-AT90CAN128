/*
  _  _ _   _    ____   ___ ____
 | || | | | |__|__ /  / __|__ /
 | __ | |_| |___|_ \ | (__ |_ \
 |_||_|\___/   |___/  \___|___/

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <adc.h>
#include <can.h>
#include <logger.h>
#include <spi_slave.h>

#include "nodes/node1.c"
#include "nodes/node2.c"
#include "nodes/node3.c"
#include "nodes/node4.c"
#include "nodes/node5.c"
#include "nodes/node6.c"
#include "nodes/node7.c"
#include "nodes/node8.c"

void spi_txdone_log_rotate(void) {
	spi_slave_register_txbuffer(logger_rotate(), LOGGER_LOG_SIZE);
}

int main(void) {
	const uint16_t node_init_val = 0x7FFF;
	uint16_t can_msg_id, adc_val;
	uint8_t can_msg[8], can_msg_size, adc_pin;

	// Initialize SPI and logger
	spi_slave_init();
	spi_slave_register_txbuffer(logger_init(), LOGGER_LOG_SIZE);
	spi_slave_register_txdone_handler(spi_txdone_log_rotate);

	// Initialize CAN
	can_init();
	can_filter(8, 0xFFFF);
	can_filter(16, 0xFFFF);
	can_filter(32, 0xFFFF);
	can_filter(64, 0xFFFF);
	can_filter(128, 0xFFFF);
	can_filter(256, 0xFFFF);
	can_filter(512, 0xFFFF);
	can_filter(1024, 0xFFFF);

	// Initialize nodes
	node1_init((void *)&node_init_val, 2);
	node2_init((void *)&node_init_val, 2);
	node3_init((void *)&node_init_val, 2);
	node4_init((void *)&node_init_val, 2);
	node5_init((void *)&node_init_val, 2);
	node6_init((void *)&node_init_val, 2);
	node7_init((void *)&node_init_val, 2);
	node8_init((void *)&node_init_val, 2);

	// Initialize ADC Trigger (tc0)
	TCCR1A = 0x00;
	TCCR1B = _BV(CS12) | _BV(CS10);
	TCCR1C = 0x00;
	TIMSK1 = 0x00;
	OCR1A = 2302;

	// Initialize ADC
	adc_init(0x03);

	// Initialize system
	sei();

	// Main loop
	while (1) {

		// Receive and handle node messages.
		while (can_message_available()) {
			can_receive(&can_msg_id, can_msg, &can_msg_size);
			switch (can_msg_id) {
				case 8:
					node1_receive(&can_msg_id, can_msg_size);
					break;
				case 16:
					node2_receive(&can_msg_id, can_msg_size);
					break;
				case 32:
					node3_receive(&can_msg_id, can_msg_size);
					break;
				case 64:
					node4_receive(&can_msg_id, can_msg_size);
					break;
				case 128:
					node5_receive(&can_msg_id, can_msg_size);
					break;
				case 256:
					node6_receive(&can_msg_id, can_msg_size);
					break;
				case 512:
					node7_receive(&can_msg_id, can_msg_size);
					break;
				case 1024:
					node8_receive(&can_msg_id, can_msg_size);
					break;
			}
		}

		// Get and process next temperature or current reading.
		if (adc_poll(&adc_pin, &adc_val)) {
			switch (adc_pin) {
				case 0: // CONV1 current
					PORTC = (adc_val << 2) & 0xF0 | PORTC & 0x0F;
					break;
				case 1: // CONV1 temp
					PORTC = PORTC & 0x0F;
					break;
			}
		}
	}

	return 0;
}