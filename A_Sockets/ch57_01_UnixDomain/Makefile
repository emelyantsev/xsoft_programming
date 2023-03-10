
FILES = us_xfr_cl us_xfr_sv
LIBDIR = ../lib
LIBNAME = common

all : ${FILES}

us_xfr_cl: us_xfr_cl.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

us_xfr_sv: us_xfr_sv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -o $@

clean :
	rm -f ${FILES}