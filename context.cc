#include "context.h"
#include "Runtime.h"


cl_context clCreateContext(const cl_context_properties *properties,
		cl_uint num_devices,
		const cl_device_id *devices,
		void (CL_CALLBACK *pfn_notify)(
			const char *, const void *, size_t, void *),
		void *user_data,
		cl_int *errcode_ret)
{
	// Check properties
	if (properties && errcode_ret)
	{
		warning("CL2HSA does not support context properties\n"
					"Context creation failed");
		*errcode_ret = CL_INVALID_PROPERTY;
		return NULL;
	}

	// Verify device id using device lists in Runtime
	auto iter = std::find(Runtime::getInstance()->device_list.begin(),
			Runtime::getInstance()->device_list.end(), devices[0]);
	if((iter == Runtime::getInstance()->device_list.end()) && (errcode_ret))
	{
		*errcode_ret = CL_INVALID_DEVICE;
		return NULL;
	}

	// Check for call-back functions
	if (user_data || pfn_notify)
	{
		warning("CL2HSA does no support function call backs for clCreateContext\n"
			"All call back funtion options will be ignored\n");
	}

	// Create Context
	cl_context context = new(struct _cl_context);
	if(context)
	{
		// Register context in runtime context list
		Runtime::getInstance()->ctx_list.push_back(context);
#if RTDEBUG
		std::cout << "Context is %u" << context;
#endif
		// Report Success
		if(errcode_ret)
			*errcode_ret = CL_SUCCESS;
	}
	else
	{
#if RTDEBUG
		std::cout << "Error allocating cl_context" << endl;
#endif
	}

	return context;
}
