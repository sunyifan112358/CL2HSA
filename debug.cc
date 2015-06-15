#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <list>
#include <algorithm>

#include "debug.h"

void cl2hsa_fatal(const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime error: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	exit(1);
}


void cl2hsa_panic(const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime panic: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	abort();
}


void cl2hsa_warning(const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime warning: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	return;
}
