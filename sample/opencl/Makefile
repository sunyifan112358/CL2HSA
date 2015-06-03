all:
	gcc -I../../include \
		-o test test.c \
		-L../../ -lcl2hsa \
		-L$(HSA_RUNTIME_PATH)/lib -lhsa-runtime64
