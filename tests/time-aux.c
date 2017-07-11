#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

enum {
  EXIT_CANCELED = 125
};

static void
errx (int eval, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vfprintf (stderr, fmt, ap);
  va_end(ap);
  exit (eval);
}

static int
get_exit_code (const char* num)
{
  long int l = 0;
  char *pch = NULL ;

  errno = 0;
  l = strtol (optarg, &pch, 10);
  if (errno != 0 || l < 0 || l > 255 || pch == optarg || *pch != '\0' )
    errx (EXIT_CANCELED, "invalid exit code '%s'", optarg);

  return (int)l;
}


static void
do_malloc (const char* optarg)
{
  float f = 0;
  long int l = 0, i = 0, multiplier = 1 ;
  void *p = NULL ;
  char* pch = NULL;

  errno = 0;
  f = strtof (optarg, &pch);
  if (errno != 0 || pch == optarg || f <= 0 )
    errx (EXIT_CANCELED, "invalid malloc request '%s'", optarg);

  /* Optional multiplier */
  switch (*pch)
    {
    case 'b':
    case 'B':
      multiplier = 1;
      pch++;
      break;

    case 'k':
    case 'K':
      multiplier = 1024;
      pch++;
      break;
    case 'm':
    case 'M':
      multiplier = 1024 * 1024 ;
      pch++;
      break;
    case 'g':
    case 'G':
      multiplier = 1024 * 1024 * 1024 ;
      pch++;
      break;
    case '\0':
      break;
    }
  if (*pch != '\0')
    errx (EXIT_CANCELED, "invalid malloc request '%s' " \
          "(multiplier error)", optarg);

  f = f * multiplier ;
  if ( f < 1 || f > 1.5 * 1024 * 1024 * 1024 )
    errx (EXIT_CANCELED, "invalid malloc request '%s' " \
          "(size too large/small)", optarg);

  l = (long int)f;
  p = malloc (l);
  if (p==NULL)
    errx (EXIT_FAILURE, "malloc failed (%ld bytes), errno=%d", l, errno);

  /* access the memory to ensure it is resident, not virtual */
  pch = (char*)p;
  for (i = 0; i < l ; i += 1000, pch += 1000)
    *pch = 4;
}

static void
do_busy_loop (const char* optarg)
{
  float f = 0;
  long int l = 0, i = 0, multiplier = 1 ;
  void *p = NULL ;
  char* pch = NULL;
  time_t end ;

  errno = 0;
  f = strtof (optarg, &pch);
  if (errno != 0 || pch == optarg || f <= 0 )
    errx (EXIT_CANCELED, "invalid busy-loop time '%s'", optarg);

  /* Optional multiplier */
  switch (*pch)
    {
    case 'n': /* nanoseconds - not supported on this system */
      errx (EXIT_CANCELED, "busy-loop with nanosecond delays is not " \
            "supported on this system");

    case 'u': /* microseconds - not supported on this system */
      errx (EXIT_CANCELED, "busy-loop with microsecond delays is not " \
            "supported on this system");

    case 's': /* seconds - default */
      multiplier = 1;
      pch++;
      break;

    case 'm': /* minutes */
    case 'M':
      multiplier = 60 ;
      pch++;
      break;

    case '\0':
      break;
    }
  if (*pch != '\0')
    errx (EXIT_CANCELED, "invalid busy-loop time '%s' " \
          "(unit error)", optarg);

  f = f * multiplier ;
  if ( f < 1 || f > 24 * 60 * 60 )
    errx (EXIT_CANCELED, "invalid busy-loop time '%s' " \
          "(too large/small)", optarg);

  /* waste one more second, to ensure we don't go below the request time,
     since the resolution is 1 second.  */
  end = time(NULL) + (int)f + 1;

  while ( time(NULL) < end ) {
  }
}


int main (int argc, char *argv[])
{
  int c;
  int rc = 0 ;

  while ( (c = getopt(argc,argv,"e:m:b:")) != -1 )
    {
      switch (c)
        {
        case 'e': /* Set exit code */
          rc = get_exit_code (optarg);
          break;

        case 'm': /* Malloc */
          do_malloc (optarg);
          break;

        case 'b': /* busy loop, waste CPU cycles for X seconds*/
          do_busy_loop (optarg);
          break;

        default:
          errx (EXIT_CANCELED,"invalid option");
        }
    }

  return rc;
}
