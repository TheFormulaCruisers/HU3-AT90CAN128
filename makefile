#
# Parameters
#===========

APPNAME     = main.elf
CXX         = avr-gcc
CXXFLAGS    = -Wall
LIBS        = -Iinc
DEVICE		= at90can128
FCPU		= 16000000
OFILES		= main.o can.o spi.o logger.o nodeman.o

#
# Make
#===========

main: $(OFILES)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(APPNAME) $(OFILES)

main.o: src/main.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/main.c $(LIBS)

can.o: src/can.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/can.c $(LIBS)

spi.o: src/spi.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/spi.c $(LIBS)

logger.o: src/logger.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/logger.c $(LIBS)

nodeman.o: src/nodeman.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/nodeman.c $(LIBS)

clean:
	rm *.o
