#
# Parameters
#===========

APPNAME     = main
CXX         = avr-gcc
CXXFLAGS    = -Wall
DEVICE		= at90can128
FCPU		= 16000000

LIBS = \
	-Iinc \
	-Ilibs/libcan/inc \
	-Ilibs/libextra/inc \
	-Ilibs/liblogger/inc \
	-Ilibs/libnode/inc \
	-Ilibs/libnodecontrol/inc \
	-Ilibs/libspi/inc

OFILES = \
	main.o \
	can.o \
	flag.o \
	logger.o \
	nodecontrol.o \
	spi_slave.o

#
# Make
#===========

main: $(OFILES)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(APPNAME) $(OFILES)

main.o: src/main.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/main.c $(LIBS)

can.o: libs/libcan/src/can.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c libs/libcan/src/can.c $(LIBS)

flag.o: libs/libextra/src/flag.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c libs/libextra/src/flag.c $(LIBS)

logger.o: libs/liblogger/src/logger.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c libs/liblogger/src/logger.c $(LIBS)

nodecontrol.o: libs/libnodecontrol/src/nodecontrol.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c libs/libnodecontrol/src/nodecontrol.c $(LIBS)

spi_slave.o: libs/libspi/src/spi_slave.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c libs/libspi/src/spi_slave.c $(LIBS)

clean:
	rm *.o
