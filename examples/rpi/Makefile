CXX      = g++
CFLAGS   = -I../..
LFLAGS   = -lwiringPi
LIB_OBJS = ../../pca9865.o ../../i2cdevice.o

.PHONY: all
all: duty_cycle_sweep zero_all set_channel

duty_cycle_sweep: duty_cycle_sweep.o $(LIB_OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

zero_all: zero_all.o $(LIB_OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

set_channel: set_channel.o $(LIB_OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

$(LIB_OBJS):
	make -C ../..

clean:
	rm -f *.o
	rm -f duty_cycle_sweep zero_all set_channel
	make -C ../.. clean

