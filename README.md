CL2HSA
---------
---------

CL2HSA is a tool that allows you to run OpenCL program in HSA mode without 
any modification in your code. 


How to use
--------------------

Known issue
--------------------
1. The OpenCL program has to invoke the clGetPlatformIDs before calling 
any other runtime functions. Since the hsa_init function is called in that 
function's implementation.
