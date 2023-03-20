
FILES = id_echo_cl id_echo_sv
LIBDIR = ../lib
LIBNAME = common
LIBNAME2 = sockets

all : ${FILES}

id_echo_cl: id_echo_cl.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

id_echo_sv: id_echo_sv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

clean :
	rm -f ${FILES}