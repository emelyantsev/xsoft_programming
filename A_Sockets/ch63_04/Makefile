
FILES = epoll_input
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

epoll_input: epoll_input.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}