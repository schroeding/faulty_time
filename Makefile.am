
ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
	-Ilib -I$(top_srcdir)/lib -I$(top_builddir)/lib \
	-Ilib2 -I$(top_srcdir)/lib2 \
	-Isrc -I$(top_srcdir)/src

##
## These must be set before including gnulib
##
CLEANFILES =
MOSTLYCLEANFILES =
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
	lib2/wait.h \
	src/time.c \
	src/resuse.c src/resuse.h

time_CFLAGS = $(WARN_CFLAGS)

time_LDADD = \
       $(top_builddir)/lib/lib$(PACKAGE).a

#SUBDIRS = . gnulib-tests

EXTRA_DIST += \
	m4/gnulib-cache.m4

info_TEXINFOS = doc/time.texi

DISTCLEANFILES =
