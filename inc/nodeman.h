#ifndef _NODEMAN_H
#define _NODEMAN_H

enum {
	NODEMAN_EVENT_START,
	NODEMAN_EVENT_RECEIVE,
	NODEMAN_EVENT_EXIT
};

typedef struct {
	uint8_t id;
	void *event_start;
	void *event_receive;
	void *event_exit;
} nodeman_node_t;

typedef struct {
	nodeman_node_t *nodes;
	uint8_t nodes_len;
} nodeman_nodes_t;

uint8_t nodeman_init();
uint8_t nodeman_node_add(uint8_t id);
uint8_t nodeman_event_handler_add(uint8_t id, uint8_t event_type, void (*event_handler)());

#endif // _NODEMAN_H