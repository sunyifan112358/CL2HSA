CL2HSA
---------
---------

CL2HSA is a tool that allows you to run OpenCL program in HSA mode without 
any modification in your code. 


How to use
--------------------
To compile on cyclops machine, set environment variables as such

	export HSA_LLVM_PATH=/opt/amd/cloc/bin
	export HSA_RUNTIME_PATH=/opt/hsa
	export PATH=$PATH:/opt/amd/cloc/bin
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/hsa/lib
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:[PATH_TO_YOUR_CL2HSA]


Known issue
--------------------
1. The OpenCL program has to invoke the clGetPlatformIDs before calling 
any other runtime functions. Since the hsa_init function is called in that 
function's implementation.
