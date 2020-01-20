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

volatile uint8_t node1_reg = 0x0A;
void node1_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= 0x0F;
	PORTC = (node1_reg & 0x0F) | (PORTC & 0xF0);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}
void node1_handle_receive(void *msg, uint8_t msg_size) {
	node1_reg ^= 0xFF;
	PORTC = (node1_reg & 0x0F) | (PORTC & 0xF0);
	logger_log(LOGGER_LOG_WHEEL1, *((uint16_t *)msg));
}

volatile uint8_t node2_reg = 0xA0;
void node2_handle_init(void *msg, uint8_t msg_size) {
	DDRC |= 0xF0;
	PORTC = (node2_reg & 0xF0) | (PORTC & 0x0F);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}
void node2_handle_receive(void *msg, uint8_t msg_size) {
	node2_reg ^= 0xFF;
	PORTC = (node2_reg & 0xF0) | (PORTC & 0x0F);
	logger_log(LOGGER_LOG_WHEEL2, *((uint16_t *)msg));
}

int main(void) {
	const uint16_t node_init_val = 0x7FFF;
	uint16_t can_id;
	uint8_t can_msg[8], can_msg_size;

	spi_slave_init();
	spi_slave_register_txbuffer(logger_init(), LOGGER_LOG_SIZE);
	spi_slave_register_txdone_handler(spi_rotate_log_buffer);

	can_init(0);
	can_filter(1);
	nodectl_node_register(1);
	nodectl_handler_register(1, node1_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(1, node1_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(1, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

	can_filter(2);
	nodectl_node_register(2);
	nodectl_handler_register(2, node2_handle_init, NODECTL_HANDLE_INIT);
	nodectl_handler_register(2, node2_handle_receive, NODECTL_HANDLE_RECEIVE);
	nodectl_handler_execute(2, (void *)&node_init_val, 2, NODECTL_HANDLE_INIT);

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