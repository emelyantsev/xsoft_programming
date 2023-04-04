
FILES = poll_pipes
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

poll_pipes: poll_pipes.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}