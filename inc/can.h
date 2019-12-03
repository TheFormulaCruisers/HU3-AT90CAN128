#ifndef _CAN_H
#define _CAN_H

/**
 * 
 */
void can_init(void);

/**
 *
 */
void can_filter(uint8_t id);

/**
 *
 */
void can_receive(uint8_t *id, uint8_t *dat, uint8_t *len);

/**
 *
 */
void can_send(uint8_t *dat, uint8_t len);

#endif // _CAN_H