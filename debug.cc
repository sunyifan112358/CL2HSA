#include "cl2hsa.h"

void cl2hsa_fatal(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime error: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	exit(1);
}


void cl2hsa_panic(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime panic: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
	fflush(NULL);
	abort();
}


void cl2hsa_warning(char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	fprintf(stderr, "\nOpenCL runtime warning: ");
	vfprintf(stderr, fmt, va);
	fprintf(stderr, "\n\n");
}
