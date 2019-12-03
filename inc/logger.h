#ifndef _LOGGER_H
#define _LOGGER_H

enum {
	LOGGER_LEVEL_NORMAL,
	LOGGER_LEVEL_WARNING,
	LOGGER_LEVEL_ERROR
};

/**
 * pkt_size	= | pkts7 | pkts6 | pkts5 | pkts4 | pkts3 | pkts2 | pkts1 | pkts0 |
 * erreg	= | errn4 | errn3 | errn2 | errn1 | errn0 | levl2 | levl1 | levl0 |
 * dat		= | ..... | ..... | ..... | ..... | ..... | ..... | ..... | .....
 */
typedef struct {
	uint8_t pkt_size;
	uint8_t erreg;
	uint8_t *dat;
} logger_t;

int logger_init();
int logger_log(uint8_t level, uint8_t id, uint8_t *dat, uint8_t dat_len);

#endif // _LOGGER_H