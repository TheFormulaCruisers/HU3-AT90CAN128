#ifndef _NODECTL_H
#define _NODECTL_H

#include <stdint.h>

/**
 * @brief Handle types.
 */
typedef enum {
	NODECTL_HANDLE_INIT,
	NODECTL_HANDLE_RECEIVE,
	NODECTL_HANDLE_EXIT
} nodectl_handle_t;

/**
 * @brief Register a node at the node controller.
 * @param id The node's unique reference.
 * @return void
 */
void nodectl_node_register(uint16_t id);

/**
 * @brief Register a handler function at a node.
 * @param id The node's reference.
 * @param handler The handler function.
 * @param type The handler's type.
 * @return void
 *
 * Registers a handler function (callback) at a node specified by the id
 * parameter. The handler must accept two parameters: a pointer to a message
 * for the handler and the size of the message, in number of bytes. The handle
 * type is defined by the nodectl_handle_t enummeration.
 */
void nodectl_handler_register(uint16_t id, void (*handler)(void *msg, uint8_t msg_size), nodectl_handle_t type);

/**
 * @brief Execute a handler associated with a node id.
 * @param id The node's reference.
 * @param msg A pointer to a message for the handler.
 * @param msg_size The size of the message, in bytes.
 * @param type The handler's type.
 * @return
 */
void nodectl_handler_execute(uint16_t id, void *msg, uint8_t msg_size, nodectl_handle_t type);

#endif // _NODECTL_H