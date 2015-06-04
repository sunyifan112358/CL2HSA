#include "stdio.h"

#include "cl2hsa.h"


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
		malloc(sizeof(struct _cl_platform_id));
	platform->platform_id = 1;
	platforms[0] = platform;
	*num_platforms = 1;

	// Return success
	return CL_SUCCESS;
}


// Device
hsa_status_t find_agent(hsa_agent_t agent, void *data)
{
	find_agent_data_t *detailed_data = (find_agent_data_t *)data;
	hsa_device_type_t filter_device_type = HSA_DEVICE_TYPE_GPU;

	// Convert from OpenCL device type to HSA device type
	switch(detailed_data->device_type)
	{
		case CL_DEVICE_TYPE_GPU:
		case CL_DEVICE_TYPE_DEFAULT:

			filter_device_type = HSA_DEVICE_TYPE_GPU;			
			break;

		case CL_DEVICE_TYPE_CPU:

			filter_device_type = HSA_DEVICE_TYPE_CPU;
			break;

		default:
			break;
	}

	// Select device
	hsa_device_type_t type;
	hsa_agent_get_info(agent, HSA_AGENT_INFO_DEVICE, &type);
	if (type == filter_device_type)
	{
		// Create device information
		cl_device_id device = malloc(sizeof(struct _cl_device_id));
		device->agent = agent;
		detailed_data->devices[*(detailed_data->num_devices)] = device;
		(*detailed_data->num_devices)++;

		// Determine if required number of device reached
		if (*detailed_data->num_devices >= 
				detailed_data->num_entries)
		{
			return HSA_STATUS_INFO_BREAK;
		}

	}

	return HSA_STATUS_SUCCESS;
}


cl_int clGetDeviceIDs(cl_platform_id platform,
		cl_device_type device_type,
		cl_uint num_entries,
		cl_device_id *devices,
		cl_uint *num_devices)
{
	// Verify platform
	if (platform[0].platform_id != 1)
	{
		return CL_INVALID_PLATFORM;
	}

	// Set number of devices to 0
	*num_devices = 0;

	// Create data
	find_agent_data_t *data = malloc(sizeof(find_agent_data_t));
	data->device_type = device_type;
	data->num_entries = num_entries;
	data->devices = devices;
	data->num_devices = num_devices;

	// Iterate through devices
	hsa_status_t err = hsa_iterate_agents(find_agent, data);
	if (err != HSA_STATUS_SUCCESS && err != HSA_STATUS_INFO_BREAK)
	{
		printf("Error iterating hsa devices.\n");
		exit(err);
	}

	// Free data
	free(data);

	return CL_SUCCESS;
}



