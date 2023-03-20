
FILES = is_echo_cl is_echo_sv
LIBDIR = ../lib
LIBNAME = common
LIBNAME2 = sockets

all : ${FILES}

is_echo_cl: is_echo_cl.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

is_echo_sv: is_echo_sv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

clean :
	rm -f ${FILES}