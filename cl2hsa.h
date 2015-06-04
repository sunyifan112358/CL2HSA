#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "include/CL/cl.h"
#include "hsa.h"

/* Debug messages */
void cl2hsa_warning(char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_fatal(char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_panic(char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

#define warning cl2hsa_warning
#define fatal cl2hsa_fatal
#define panic cl2hsa_panic

// A struct that has all the data related to the process of iterating agents
typedef struct find_agent_data
{
	cl_device_type device_type;
	cl_uint num_entries;
	cl_device_id *devices;
	cl_uint *num_devices;
} find_agent_data_t;

// Platform Structures
struct _cl_platform_id
{
	uint64_t platform_id;
};

//  Device Structures
struct _cl_device_id
{
	hsa_agent_t agent;
};
