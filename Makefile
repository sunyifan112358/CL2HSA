<<<<<<< HEAD
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
	$(CC) -o $@ $^ $(CXXFLAGS) -shared -DHSADEBUG

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)


all: libcl2hsa.so
=======
all:
	gcc -o libcl2hsa.so -fPIC\
		-Iinclude/ \
		-I$(HSA_RUNTIME_PATH)/include/ \
		-Wall -Werror \
		-DHSADEBUG\
		cl2hsa.c context.c command_queue.c debug.c -shared
>>>>>>> 238a21d4260b9d935e62690e24c9668f75caddf3

clean:
	rm -f *.so *.o
