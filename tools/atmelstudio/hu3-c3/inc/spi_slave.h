#ifndef _SPI_SLAVE_H
#define _SPI_SLAVE_H

/**
 * @brief Initialize and enable the SPI controller.
 * @param void
 * @return void
 */
void spi_slave_init(void);

/**
 * @brief Register the transmission data buffer.
 * @param txbuffer
 * @param txbuflen
 * @return void
 */
void spi_slave_register_txbuffer(uint8_t *txbuffer, uint8_t txbuflen);

/**
 * @brief Register the transmission start handler.
 * @param txstart_handler
 * @return void
 *
 * Start of transmission is detected after the first byte transferred.
 * In other words, the first byte of the then registered txbuffer will be
 * transmitted before calling this handler. If this function will be used for
 * registering another txbuffer at the start of a new transmission, this effect
 * should be taken into consideration.
 */
void spi_slave_register_txstart_handler(void (*txstart_handler)());

/**
 * @brief Register the transmission done handler.
 * @param txdone_handler
 * @return void
 */
void spi_slave_register_txdone_handler(void (*txdone_handler)());

#endif // _SPI_SLAVE_H