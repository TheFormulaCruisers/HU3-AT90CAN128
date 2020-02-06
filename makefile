#
# Parameters
#===========

APPNAME     = c3-firmware
MCU			= at90can128
F_CPU		= 16000000
GCC         = avr-gcc -Wall -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O2
OBJCOPY		= avr-objcopy -O ihex ${APPNAME}.elf bin/${APPNAME}.hex
FLASH		= avrdude -c dragon_jtag -p $(MCU) -P usb

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
	$(OBJCOPY)

main.o: src/main.c
	$(GCC) -c src/main.c $(LIBS)

can.o: libs/libcan/src/can.c
	$(GCC) -c libs/libcan/src/can.c $(LIBS)

logger.o: libs/liblogger/src/logger.c
	$(GCC) -c libs/liblogger/src/logger.c $(LIBS)

spi_slave.o: libs/libspi/src/spi_slave.c
	$(GCC) -c libs/libspi/src/spi_slave.c $(LIBS)

adc.o: libs/libadc/src/adc.c
	$(GCC) -c libs/libadc/src/adc.c $(LIBS) -DADC_START_TC1_COMP

flash:
	$(FLASH) -e -U flash:w:bin/$(APPNAME).hex

clean:
	rm *.o *.elf