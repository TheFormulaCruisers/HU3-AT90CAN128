#ifndef _LOGGER_H
#define _LOGGER_H

/**
 * @brief Log value types.
 */
typedef enum {
	LOGGER_LOG_SYSTEM,
	LOGGER_LOG_THROTTLE,
	LOGGER_LOG_BRAKE,
	LOGGER_LOG_WHEEL1,
	LOGGER_LOG_SIZE
} logger_log_t;

/**
 * @brief Initialize the logger.
 * @param void
 * @return Pointer to the static (readable) buffer.
 */
void *logger_init(void);

/**
 * @brief Write a value to the log.
 * @param type
 * @param value
 * @return void
 */
void logger_log(logger_log_t type, uint16_t value);

/**
 * @brief Rotate the log.
 * @param void
 * @return Pointer to the static (readable) buffer.
 */
void *logger_rotate(void);

#endif // _LOGGER_H