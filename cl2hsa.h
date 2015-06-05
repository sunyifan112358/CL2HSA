#ifndef CL2HSA_H
#define CL2HSA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "include/CL/cl.h"
#include "hsa.h"

/* Debug messages */
void cl2hsa_warning(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_fatal(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_panic(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

#define warning cl2hsa_warning
#define fatal cl2hsa_fatal
#define panic cl2hsa_panic

#endif
