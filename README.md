CL2HSA
---------
---------

CL2HSA is a tool that allows you to run OpenCL program in HSA mode without 
any modification in your code. 


How to use
--------------------
To compile on cyclops machine, set environment variables as such

	export hsa_llvm_path=/opt/amd/cloc/bin
	export hsa_runtime_path=/opt/hsa
	export path=$path:/opt/amd/cloc/bin
	export ld_library_path=/opt/hsa/lib
	export ld_library_path=$ld_library_path:/home/yifan/hsa/cl2hsa/




Known issue
--------------------
1. The OpenCL program has to invoke the clGetPlatformIDs before calling 
any other runtime functions. Since the hsa_init function is called in that 
function's implementation.
