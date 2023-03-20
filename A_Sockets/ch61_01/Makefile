
FILES = socknames
LIBDIR = ../lib
LIBNAME = common
LIBNAME2 = sockets

all : ${FILES}

socknames: socknames.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

clean :
	rm -f ${FILES}