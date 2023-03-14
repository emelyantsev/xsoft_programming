
FILES = t_gethostbyname
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

t_gethostbyname: t_gethostbyname.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}