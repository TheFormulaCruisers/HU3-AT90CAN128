/*
  _  _ _   _    ____   ___ ____
 | || | | | |__|__ /  / __|__ /
 | __ | |_| |___|_ \ | (__ |_ \
 |_||_|\___/   |___/  \___|___/

*/

#include <avr/io.h>
#include <avr/interrupt.h>

#include <can.h>
#include <logger.h>
#include <nodectl.h>
#include <spi_slave.h>

void spi_rotate_log_buffer(void) {
	spi_slave_register_txbuffer(logger_rotate(), LOGGER_LOG_SIZE);
}

volatile const uint8_t node1_msk = 1;
volatile uint8_t node1_reg = 1;
void node1_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node1_msk;
	PORTC = node1_msk | (PORTC & ~node1_msk);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}
void node1_handle_receive(void *msg, uint8_t msg_size) {
	node1_reg ^= node1_msk;
	PORTC = node1_reg | (PORTC & ~node1_msk);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}

volatile const uint8_t node2_msk = 2;
volatile uint8_t node2_reg = 2;
void node2_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node2_msk;
	PORTC = node2_msk | (PORTC & ~node2_msk);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}
void node2_handle_receive(void *msg, uint8_t msg_size) {
	node2_reg ^= node2_msk;
	PORTC = node2_reg | (PORTC & ~node2_msk);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}

volatile const uint8_t node3_msk = 4;
volatile uint8_t node3_reg = 4;
void node3_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node3_msk;
	PORTC = node3_msk | (PORTC & ~node3_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node3_handle_receive(void *msg, uint8_t msg_size) {
	node3_reg ^= node3_msk;
	PORTC = node3_reg | (PORTC & ~node3_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

volatile const uint8_t node4_msk = 8;
volatile uint8_t node4_reg = 8;
void node4_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node4_msk;
	PORTC = node4_msk | (PORTC & ~node4_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node4_handle_receive(void *msg, uint8_t msg_size) {
	node4_reg ^= node4_msk;
	PORTC = node4_reg | (PORTC & ~node4_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

volatile const uint8_t node5_msk = 16;
volatile uint8_t node5_reg = 16;
void node5_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node5_msk;
	PORTC = node5_msk | (PORTC & ~node5_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node5_handle_receive(void *msg, uint8_t msg_size) {
	node5_reg ^= node5_msk;
	PORTC = node5_reg | (PORTC & ~node5_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

volatile const uint8_t node6_msk = 32;
volatile uint8_t node6_reg = 32;
void node6_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node6_msk;
	PORTC = node6_msk | (PORTC & ~node6_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node6_handle_receive(void *msg, uint8_t msg_size) {
	node6_reg ^= node6_msk;
	PORTC = node6_reg | (PORTC & ~node6_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

volatile const uint8_t node7_msk = 64;
volatile uint8_t node7_reg = 64;
void node7_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node7_msk;
	PORTC = node7_msk | (PORTC & ~node7_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node7_handle_receive(void *msg, uint8_t msg_size) {
	node7_reg ^= node7_msk;
	PORTC = node7_reg | (PORTC & ~node7_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

volatile const uint8_t node8_msk = 128;
volatile uint8_t node8_reg = 128;
void node8_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= node8_msk;
	PORTC = node8_msk | (PORTC & ~node8_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}
void node8_handle_receive(void *msg, uint8_t msg_size) {
	node8_reg ^= node8_msk;
	PORTC = node8_reg | (PORTC & ~node8_msk);
	logger_log(LOGGER_LOG_THROTTLE, *((uint16_t *)msg));
}

int main(void) {
	const uint16_t node_init_val = 0x7FFF;
	uint16_t can_id;
	uint8_t can_msg[8], can_msg_size;

	spi_slave_init();
	spi_slave_register_txbuffer(logger_init(), LOGGER_LOG_SIZE);
	spi_slave_register_txdone_handler(spi_rotate_log_buffer);

	can_init(0);
	can_filter(8);
	nodectl_node_register(8);
	nodectl_handler_register(8, node1_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(8, node1_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(8, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(16);
	nodectl_node_register(16);
	nodectl_handler_register(16, node2_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(16, node2_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(16, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(32);
	nodectl_node_register(32);
	nodectl_handler_register(32, node3_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(32, node3_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(32, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(64);
	nodectl_node_register(64);
	nodectl_handler_register(64, node4_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(64, node4_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(64, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(128);
	nodectl_node_register(128);
	nodectl_handler_register(128, node5_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(128, node5_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(128, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(256);
	nodectl_node_register(256);
	nodectl_handler_register(256, node6_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(256, node6_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(256, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(512);
	nodectl_node_register(512);
	nodectl_handler_register(512, node7_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(512, node7_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(512, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(1024);
	nodectl_node_register(1024);
	nodectl_handler_register(1024, node8_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(1024, node8_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(1024, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);
	
	sei();

	// Main loop
	while (1) {

		/* Get received node messages and hand them
		 * to the corresponding node handler. */
		while (can_message_available()) {
			can_receive(&can_id, can_msg, &can_msg_size);
			nodectl_handler_execute(can_id, can_msg, can_msg_size, NODECTL_HANDLE_RECEIVE);
		}
	}

	return 0;
}