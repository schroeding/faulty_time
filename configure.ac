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
	dist-xz
	color-tests
	parallel-tests
])

dnl Minimum Autoconf version required.
AC_PREREQ([2.62])


dnl Where to generate output; srcdir location.
AC_CONFIG_HEADERS([config.h:config.in])
AC_CONFIG_SRCDIR([src/time.c])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL

# Since we use gnulib: gl_EARLY must be called as soon as possible after
# the C compiler is checked.  The others could be later, but we just
# keep everything together.
gl_EARLY
gl_INIT

# Add extra compilation warnings. These will only apply to datamash.c not to
# any gnulib modules). See $(WARN_CFLAGS) in Makefile.am
gl_WARN_ADD([-Wall])
gl_WARN_ADD([-Wextra])
gl_WARN_ADD([-Wformat-security])
gl_WARN_ADD([-Wswitch-enum])
gl_WARN_ADD([-Wswitch-default])
gl_WARN_ADD([-Wformat-nonliteral])
gl_WARN_ADD([-Wunused-parameter])
gl_WARN_ADD([-Wfloat-equal])
gl_WARN_ADD([-fdiagnostics-show-option])
gl_WARN_ADD([-funit-at-a-time])
gl_WARN_ADD([-Wmissing-format-attribute])
gl_WARN_ADD([-Wstrict-overflow])
gl_WARN_ADD([-Wsuggest-attribute=const])
gl_WARN_ADD([-Wsuggest-attribute=pure])
AC_SUBST([WARN_CFLAGS])

dnl Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(sys/rusage.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SIGNAL

AC_MSG_CHECKING(for struct timeval in sys/time.h)
AC_EGREP_HEADER(tv_usec, sys/time.h, have_tv=yes, have_tv=no)
AC_MSG_RESULT($have_tv)
if test $have_tv = yes ; then
  AC_DEFINE([HAVE_TIMEVAL], [1], [Have TIMEVAL])
fi

dnl Checks for library functions.
AC_FUNC_VPRINTF
AC_FUNC_WAIT3
AC_CHECK_FUNCS(strerror)

# This is needed when building outside the source dir
# with --disable-dependency-tracking.
# Inspired by sed's https://bugs.gnu.org/25371
AS_MKDIR_P([lib])
AS_MKDIR_P([src])
AS_MKDIR_P([doc])
AS_MKDIR_P([tests])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
