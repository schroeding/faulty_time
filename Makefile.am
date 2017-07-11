
ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
	-Ilib -I$(top_srcdir)/lib -I$(top_builddir)/lib \
	-Isrc -I$(top_srcdir)/src

##
## These must be set before including gnulib
##
CLEANFILES =
MOSTLYCLEANFILES =
MOSTLYCLEANDIRS =
MAINTAINERCLEANFILES =
noinst_LIBRARIES =
EXTRA_DIST =
BUILT_SOURCES =


##
## gnulib as library, when used in non-recursive makefile
##
include lib/gnulib.mk

lib_libtime_a_CPPFLAGS = $(AM_CPPFLAGS) -I$(top_srcdir)/lib/ \
			-I$(top_builddir)/lib
lib_libtime_a_CFLAGS = $(AM_CFLAGS) $(GNULIB_WARN_CFLAGS) $(WERROR_CFLAGS)

#TODO: add '$(ALLOCA)' ??
lib_libtime_a_LIBADD += $(LIBOBJS)
lib_libtime_a_DEPENDENCIES += $(LIBOBJS)

##
## GNU Time
##
bin_PROGRAMS = time

time_SOURCES = \
	src/time.c \
	src/resuse.c src/resuse.h \
	src/rusage-kb.h src/rusage-kb.c

time_CFLAGS = $(WARN_CFLAGS)

time_LDADD = \
       $(top_builddir)/lib/lib$(PACKAGE).a

#SUBDIRS = . gnulib-tests

EXTRA_DIST += \
	m4/gnulib-cache.m4

info_TEXINFOS = doc/time.texi

DISTCLEANFILES =

##
## Tests
##
TESTS = tests/help-version.sh

TEST_EXTENSIONS = .sh

EXTRA_DIST += tests/init.sh \
	$(TESTS)

# Note: the "9>&2" redirection is part of Automake's parallel-tests.
#       see also stderr_fileno in 'init.cfg'
TESTS_ENVIRONMENT = \
  top_srcdir=$(abs_top_srcdir) \
  PATH='$(abs_top_builddir)$(PATH_SEPARATOR)'$$PATH \
  LC_ALL=C \
  VERSION='$(VERSION)' \
  test_dir='$(abs_top_srcdir)/tests' ; \
  export top_srcdir PATH LC_ALL VERSION test_dir ; \
  9>&2
