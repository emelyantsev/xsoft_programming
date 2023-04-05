
FILES = demo_sigio
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

demo_sigio: demo_sigio.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}