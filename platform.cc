#include "platform.h"

cl_int clGetPlatformIDs(cl_uint num_entries, 
		cl_platform_id *platforms,
		cl_uint *num_platforms)
{
	// This function is usually the first to be called. Therefore, let it
	// call hsa_init
	hsa_init();

	// Validate arguments
	if (num_entries == 0 && platforms != NULL)
	{
		return CL_INVALID_VALUE;
	}
	else if ( platforms == NULL && num_platforms == NULL)
	{
		return CL_INVALID_VALUE;
	}

	// Set value
	struct _cl_platform_id *platform = 
		(struct _cl_platform_id *)malloc(
				sizeof(struct _cl_platform_id));
	platform->platform_id = 1;
	platforms[0] = platform;
	*num_platforms = 1;

	// Return success
	return CL_SUCCESS;
}


