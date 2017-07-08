
AM_CPPFLAGS = -Ilib -I$(top_srcdir)/lib -Isrc -I$(top_srcdir)/src

bin_PROGRAMS = time

time_SOURCES = \
	lib/getopt.h lib/getpagesize.h \
	lib/port.h lib/wait.h \
	lib/getopt.c lib/getopt1.c lib/error.c \
	src/time.c \
	src/resuse.c src/resuse.h \
	src/version.c

EXTRA_DIST = texinfo.tex

info_TEXINFOS = doc/time.texi

DISTCLEANFILES =
