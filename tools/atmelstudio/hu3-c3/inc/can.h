#ifndef _CAN_H
#define _CAN_H

/**
 * @brief Initialize the CAN controller.
 * @param txid The message ID used for transmission.
 * @return void
 *
 * Resets the CAN controller, sets its transmission speed and its protocol
 * revision (2.0A or 2.0B) for transmission, enables interrupts, clears all
 * message objects and enables the CAN controller.
 *
 * Currently, the transmission speed is fixed at 1Mbps.
 */
void can_init(uint16_t txid);

/**
 * @brief Configure a message object to filter on a specific message ID.
 * @param rxid The message ID to filter on.
 * @return void
 *
 * Selects the next available message object and configures it to filter the
 * bus on messages with the message ID specified. Message objects are 
 * utilized chronologically and reception is enabled immediately. The first
 * message object is reserved for transmission and will not be available for
 * reception.
 * 
 * Best practice is to filter messages in descending order of priority. That
 * way, the receive function will favor a high priority message over a low
 * priority message.
 */
void can_filter(uint16_t rxid);

/**
 * @brief Check if new messages are available.
 * @param void
 * @return (1) if new messages are available, (0) otherwise.
 */
uint8_t can_message_available(void);

/**
 * @brief Retrieve a message from the first message object with a set rx flag.
 * @param rxid A pointer to where the message ID will be copied.
 * @param msg A pointer to where the message will be copied.
 * @param msg_size A pointer to where the message size will be copied.
 * @return void
 *
 * Finds the highest priority message object with a set RX flag. The id,
 * message and message length of the MOb are then copied to the respective
 * memory locations pointed to by the function's parameters. Make sure to
 * reserve enough memory at these locations.
 */
void can_receive(uint16_t *rxid, uint8_t *msg, uint8_t *msg_size);

/**
 * @brief Transmit a message on the bus.
 * @param msg A pointer to where the message is stored.
 * @param msg_size The number of bytes to transmit.
 * @return void
 *
 * Copies the number of bytes specified by len from the memory pointed to by
 * dat to the transmission message object and starts transmission. If the
 * transmission message object is busy, the message is stored in a buffer. Once
 * the preceding transmission has been completed, the new data is loaded from
 * the buffer and transmitted automatically.
 */
void can_transmit(uint8_t *msg, uint8_t msg_size);

#endif // _CAN_H