#ifndef RUNTIME_H
#define RUNTIME_H

#include <memory>

#include "cl2hsa.h"

/// Runtime is a singleton that keeps global state information
class Runtime 
{

	// Global only instance
	static std::unique_ptr<Runtime> instance;

	// Private constructor
	Runtime();

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
};

#endif
