
AM_CPPFLAGS = -Ilib2 -I$(top_srcdir)/lib2 -Isrc -I$(top_srcdir)/src

bin_PROGRAMS = time

time_SOURCES = \
	lib2/getopt.h lib2/getpagesize.h \
	lib2/port.h lib2/wait.h \
	lib2/getopt.c lib2/getopt1.c lib2/error.c \
	src/time.c \
	src/resuse.c src/resuse.h

EXTRA_DIST = texinfo.tex

info_TEXINFOS = doc/time.texi

DISTCLEANFILES =
