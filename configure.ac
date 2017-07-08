dnl Process this file with autoconf to produce a configure script.

AC_INIT([GNU Time],
	[1.7.3],
	[bug-time@gnu.org], [],
	[https://www.gnu.org/software/time/])

dnl Must come before AM_INIT_AUTOMAKE.
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([
	1.11.1
	subdir-objects
])

dnl Minimum Autoconf version required.
AC_PREREQ([2.62])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL

dnl Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(unistd.h string.h sys/rusage.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SIGNAL

AC_MSG_CHECKING(for struct timeval in sys/time.h)
AC_EGREP_HEADER(tv_usec, sys/time.h, have_tv=yes, have_tv=no)
AC_MSG_RESULT($have_tv)
test $have_tv = yes && AC_DEFINE(HAVE_TIMEVAL)

dnl Checks for library functions.
AC_FUNC_VPRINTF
AC_FUNC_WAIT3
AC_CHECK_FUNCS(strerror)

AC_MSG_CHECKING(for getpagesize)
AC_TRY_LINK([#include <sys/param.h>],
[getpagesize();], have_gp=yes, have_gp=no)
AC_MSG_RESULT($have_gp)
test $have_gp = yes && AC_DEFINE(HAVE_GETPAGESIZE)


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
