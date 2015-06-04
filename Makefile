all:
	gcc -o libcl2hsa.so -fPIC\
		-Iinclude/ \
		-I$(HSA_RUNTIME_PATH)/include/ \
		-Wall -Werror \
		cl2hsa.c context.c command_queue.c debug.c -shared

clean:
	rm -f *.so *.o
