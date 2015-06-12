#include "device.h"
#include "command_queue.h"

// Implementation of a Command Queue in OpenCL 1.0/1.1/1.2
// This particular definition of command queue is deprecated for OpenCL 2.0
cl_command_queue clCreateCommandQueue(cl_context context,
			cl_device_id device,
			cl_command_queue_properties properties,
			cl_int *errcode_ret)
{

	cl_command_queue command_queue = NULL;

	// Validate arguments
	// Check for context and device
	if(context == NULL)
	{
		if (errcode_ret)
			*errcode_ret = CL_INVALID_CONTEXT;
		return command_queue;
	}
	else
	{
		// TODO: Add a check to see if the context
		// pointer is not garbage.
	}

	//Check for device
	if(device == NULL)
	{
		if (errcode_ret)
			*errcode_ret = CL_INVALID_DEVICE;
		return command_queue;
	}
	else
	{
		// TODO: Check to see if the device is valid for
		// the given context. A context list has to be maintained,
		// with each context having its associated devices.
	}

	// Check properties
	if (properties)
	{

		if (properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE)
		{
			warning("CL2HSA does not support out-of-order command queues.\n"
					"Defaulting too in-order command queue\n");
		}
		if (properties & CL_QUEUE_PROFILING_ENABLE)
		{
			warning("CL2HSA does not support event based profiling.\n"
					"Time stamps related to events will be inaccurate.\n");
		}
	}

	// Create an OpenCL command queue usign HSA constructs
	command_queue = (cl_command_queue)malloc(sizeof(struct _cl_command_queue));
	command_queue->device = device;
	command_queue->context = context;

	// Query the maximum size of the HSA queue
	command_queue->queue_size = 0;
	hsa_status_t err;
	err = hsa_agent_get_info(device->agent,
			HSA_AGENT_INFO_QUEUE_MAX_SIZE, 
			&command_queue->queue_size);

#if HSADEBUG
	std::cout << "The maximum queue size is %u.\n"
		<< (unsigned int) command_queue->queue_size;
#endif

	// Create a new HSA queue
	err = hsa_queue_create(command_queue->device->agent, 
			command_queue->queue_size,
			HSA_QUEUE_TYPE_SINGLE, NULL, NULL, 
			UINT32_MAX, UINT32_MAX,
			&command_queue->queue);
	if (err != HSA_STATUS_SUCCESS)
	{
#if HSADEBUG
		std::cout << "Command Queue Creation failed.\n";
#endif
		exit(1);
	}

	if (errcode_ret)
			*errcode_ret = CL_SUCCESS;

	return command_queue;
}


