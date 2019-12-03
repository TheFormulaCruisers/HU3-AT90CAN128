#ifndef _SPI_H
#define _SPI_H

int spi_init();
int spi_send(uint8_t *dat, uint8_t dat_len);

#endif // _SPI_H