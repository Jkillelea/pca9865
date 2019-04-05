# g++ duty_cycle_sweep.cpp ../../*.cpp  -I../.. -lwiringPi

CXX := g++
CFLAGS = -I../..
LFLAGS := -lwiringPi

LIB_OBJS := pca9865.o i2cdevice.o

.PHONY: all
all: duty_cycle_sweep zero_all $(LIB_OBJS)

$(LIB_OBJS):
	make -C ../..

%: %.o
	$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm *.o
	rm duty_cycle_sweep zero_all
	make -C ../.. clean


