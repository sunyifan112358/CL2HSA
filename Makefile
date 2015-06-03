all:
	gcc -o libcl2hsa.so -fPIC\
		-Iinclude/ \
		-I$(HSA_RUNTIME_PATH)/include/ \
		-Wall -Werror \
		cl2hsa.c context.c -shared
