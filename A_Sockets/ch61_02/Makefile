
FILES = scm_rights_send scm_rights_recv
LIBDIR = ../lib
LIBNAME = common
LIBNAME2 = sockets

all : ${FILES}

scm_rights_send: scm_rights_send.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

scm_rights_recv: scm_rights_recv.c
	gcc $^ -g -L${LIBDIR} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

clean :
	rm -f ${FILES}