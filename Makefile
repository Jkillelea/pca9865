CXX := g++
CFLAGS := -I.
LFLAGS := 

.PHONY: all
all: lib

lib: pca9865.o i2cdevice.o

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@ $(LFLAGS)

.PHONY: clean
clean:
	rm *.o

