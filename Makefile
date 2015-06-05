IFLAG = -Iinclude/ -I/$(HSA_RUNTIME_PATH)/include/
CC = g++
CXXFLAGS = $(IFLAG) -Wall -Werror -fPIC -std=c++11

DEPS = %.h

OBJ = Runtime.o \
      platform.o \
      context.o \
      command_queue.o \
      debug.o \
      device.o

libcl2hsa.so: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -shared

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)


all: libcl2hsa.so

clean:
	rm -f *.so *.o
