#include "cl2hsa.h"

// A struct that has all the data related to the process of iterating agents
typedef struct find_agent_data
{
	cl_device_type device_type;
	cl_uint num_entries;
	cl_device_id *devices;
	cl_uint *num_devices;
} find_agent_data_t;

//  Device Structures
struct _cl_device_id
{
	hsa_agent_t agent;
};
