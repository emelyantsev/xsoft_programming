
FILES = t_select
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

t_select: t_select.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}