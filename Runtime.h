#ifndef RUNTIME_H
#define RUNTIME_H

#include <memory>
#include <list>

#include "cl2hsa.h"

/// Runtime is a singleton that keeps global state information
class Runtime 
{

	// Global only instance
	static std::unique_ptr<Runtime> instance;

	// Private constructor
	Runtime() {};

public:

	/// Get the pointer to the global only instance
	static Runtime *getInstance()
	{
		if (!instance.get())
		{
			instance.reset(new Runtime());
		}
		return instance.get();
	}

	// List for managing devices
	std::list<cl_device_id> device_list;

	// List for managing contexts
	std::list<cl_context> ctx_list;

	// List for command queues
	std::list<cl_command_queue> cmd_queue_list;
};

#endif
