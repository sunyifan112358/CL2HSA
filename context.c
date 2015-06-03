#include "context.h"

cl_context clCreateContext(const cl_context_properties *properties,
		cl_uint num_devices,
		const cl_device_id *devices,
		void (CL_CALLBACK *pfn_notify)(
			const char *, const void *, size_t, void *),
		void *user_data,
		cl_int *errcode_ret)
{
	cl_context context = malloc(sizeof(struct _cl_context));
	return context;
}
