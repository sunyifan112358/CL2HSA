#include "cl2hsa.h"

struct _cl_command_queue
{
	uint32_t queue_size;
	hsa_queue_t* queue;
	cl_device_id device;
	cl_context context;
};
