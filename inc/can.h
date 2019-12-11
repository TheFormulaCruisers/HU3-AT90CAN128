#ifndef _CAN_H
#define _CAN_H

/**
 * @brief Initialize the CAN controller.
 * @param void
 * @return void
 *
 * Resets the CAN controller, sets its transfer speed and its protocol revision
 * (2.0A or 2.0B) for transmission, enables interrupts, clears all message
 * objects and enables the CAN controller.
 *
 * Currently, the transfer speed is set to 1MBps, the protocol revision is set
 * to 2.0A and no interrupts are enabled.
 */
void can_init(void);

/**
 * @brief Configure a message object to filter on a specific message ID.
 * @param id The message ID to filter on.
 * @return void
 *
 * Finds an unused message object and configures it to filter the bus on
 * messages with the message ID specified. Reception is enabled immediately.
 * 
 * The first message object is reserved for transmission and will not be
 * available for reception. The transmission message object uses message ID 0
 * and has the highest priority on the bus.
 */
void can_filter(uint16_t id);

/**
 * @brief Retrieve a message from the first message object with a set rx flag.
 * @param id A pointer to where the message ID will be copied.
 * @param dat A pointer to where the message will be copied.
 * @param len A pointer to where the mesasage length will be copied.
 * @return void
 */
void can_receive(uint16_t *id, uint8_t *dat, uint8_t *len);

/**
 * @brief Transmit a message on the bus.
 * @param dat A pointer to where the message is stored.
 * @param len The number of bytes to transmit.
 * @return void
 *
 * Copies the number of bytes specified by len from the memory pointed to by
 * dat to the transmission message object and starts transmission.
 */
void can_transmit(uint8_t *dat, uint8_t len);

#endif // _CAN_H