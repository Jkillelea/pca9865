# g++ duty_cycle_sweep.cpp ../../*.cpp  -I../.. -lwiringPi

CXX = g++
CFLAGS = -I../..
LFLAGS = -lwiringPi

LIB_OBJS = pca9865.o i2cdevice.o

.PHONY: all
all: duty_cycle_sweep zero_all $(LIB_OBJS)

$(LIB_OBJS):
	make -C ../..

duty_cycle_sweep: duty_cycle_sweep.o
	$(cxx) -o $@ $^ $(lflags)

zero_all: zero_all.o
	$(cxx) -o $@ $^ $(lflags)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^

.PHONY: clean
clean:
	rm -f *.o
	rm -f duty_cycle_sweep zero_all
	make -C ../.. clean


