IFLAG = -Iinclude/ -I$(HSA_RUNTIME_PATH)/include/
CC = g++
CXXFLAGS = $(IFLAG) -fPIC -Wall -Werror -std=c++11

DEPS = %.h

OBJ = debug.o \
      Runtime.o \
      platform.o \
      context.o \
      command_queue.o \
      device.o 

libcl2hsa.so: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -shared -DHSADEBUG -DRTDEBUG

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)


all: libcl2hsa.so

clean:
	rm -f *.so *.o
