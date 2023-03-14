
FILES = t_getservbyname
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

t_getservbyname: t_getservbyname.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}