CXX      = g++
CFLAGS   = -I../..
LFLAGS   = -lwiringPi
LIB_OBJS = ../../pca9865.o ../../i2cdevice.o

.PHONY: all
all: duty_cycle_sweep zero_all set_channel $(LIB_OBJS)

duty_cycle_sweep: duty_cycle_sweep.o 
	$(CXX) -o $@ $^ $(LIB_OBJS) $(LFLAGS)
zero_all: zero_all.o 
	$(CXX) -o $@ $^ $(LIB_OBJS) $(LFLAGS)
set_channel: set_channel.o 
	$(CXX) -o $@ $^ $(LIB_OBJS) $(LFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

$(LIB_OBJS):
	make -C ../..

clean:
	rm -f *.o
	rm -f duty_cycle_sweep zero_all
	make -C ../.. clean


