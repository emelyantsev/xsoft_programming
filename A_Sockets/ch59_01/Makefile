
FILES = i6d_ucase_cl i6d_ucase_sv
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

i6d_ucase_cl: i6d_ucase_cl.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

i6d_ucase_sv: i6d_ucase_sv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}