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
