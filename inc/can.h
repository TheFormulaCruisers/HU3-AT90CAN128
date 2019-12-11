#ifndef _CAN_H
#define _CAN_H

/**
 * @brief Initialize the CAN controller.
 * @param void
 * @return void
 *
 * Resets the CAN controller, sets its transmission speed and its protocol 
 * revision (2.0A or 2.0B) for transmission, enables interrupts, clears all 
 * message objects and enables the CAN controller.
 *
 * Currently, the transmission speed is set to 1MBps, the protocol revision is
 * 2.0A and no interrupts are enabled.
 */
void can_init(void);

/**
 * @brief Configure a message object to receive messages from a node.
 * @param id The node ID to filter messages from.
 * @return void
 *
 * Finds an unused message object and configures it to receive messages from
 * the node ID specified. Reception is enabled immediately.
 * 
 * The first message object (MOb0) is reserved for transmitting messages and
 * will not be available for reception.
 */
void can_filter(uint16_t id);

/**
 * @brief
 * @param
 * @return
 */
void can_receive(uint16_t *id, uint8_t *dat, uint8_t *len);

/**
 * @brief
 * @param
 * @return
 */
void can_transmit(uint8_t *dat, uint8_t len);

#endif // _CAN_H