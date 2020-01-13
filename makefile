#
# Parameters
#===========

APPNAME     = main
CXX         = avr-gcc
CXXFLAGS    = -Wall
LIBS        = -Iinc
DEVICE		= at90can128
FCPU		= 16000000
OFILES		= main.o

#
# Make
#===========

main: $(OFILES)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(APPNAME) $(OFILES)

main.o: src/main.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/main.c $(LIBS)

clean:
	rm *.o
