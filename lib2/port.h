/* port.h -- portability declarations for GNU time */

#if __STDC__
# define PTR void *
#else
# define PTR char *
#endif

#if STDC_HEADERS || HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#if STDC_HEADERS
#include <limits.h>
#include <stdlib.h>
#else
char *getenv (const char *var);
PTR malloc (size_t sz);
#endif
#ifndef LONG_MAX
#define	LONG_MAX (~(1 << (sizeof (long) * 8 - 1)))
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
#endif
