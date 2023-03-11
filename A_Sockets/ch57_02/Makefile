
FILES = ud_ucase_cl ud_ucase_sv
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

ud_ucase_cl: ud_ucase_cl.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

ud_ucase_sv: ud_ucase_sv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}