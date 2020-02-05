#
# Parameters
#===========

APPNAME     = c3-firmware
GCC         = avr-gcc -Wall -mmcu=at90can128 -DF_CPU=16000000 -O2
OBJCOPY		= avr-objcopy

LIBS = \
	-Iinc \
	-Ilibs/libcan/inc \
	-Ilibs/liblogger/inc \
	-Ilibs/libspi/inc \
	-Ilibs/libadc/inc

OFILES = \
	main.o \
	can.o \
	logger.o \
	spi_slave.o \
	adc.o

#
# Make
#===========

build: $(OFILES)
	$(GCC) -o $(APPNAME).elf $(OFILES)
	$(OBJCOPY) -O ihex ${APPNAME}.elf bin/${APPNAME}.hex

main.o: src/main.c
	$(GCC) -c src/main.c $(LIBS)

can.o: libs/libcan/src/can.c
	$(GCC) -c libs/libcan/src/can.c $(LIBS)

logger.o: libs/liblogger/src/logger.c
	$(GCC) -c libs/liblogger/src/logger.c $(LIBS)

spi_slave.o: libs/libspi/src/spi_slave.c
	$(GCC) -c libs/libspi/src/spi_slave.c $(LIBS)

adc.o: libs/libadc/src/adc.c
	$(GCC) -c libs/libadc/src/adc.c $(LIBS)

clean:
	rm *.o *.elf