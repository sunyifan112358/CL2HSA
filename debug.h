#ifndef DEBUG_H
#define DEBUG_H

#define warning cl2hsa_warning
#define fatal cl2hsa_fatal
#define panic cl2hsa_panic

// Debug messages
void cl2hsa_warning(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_fatal(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void cl2hsa_panic(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

#endif
