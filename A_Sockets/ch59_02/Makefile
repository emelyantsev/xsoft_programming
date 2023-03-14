
FILES = is_seqnum_cl is_seqnum_sv
LIBDIR = ../lib
LIBNAME = common
LIBNAME2 = readline
LIBDIR2 = .

all : ${FILES}

is_seqnum_cl: is_seqnum_cl.c lib${LIBNAME2}.so
	gcc -g $< -L${LIBDIR} -L${LIBDIR2} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

is_seqnum_sv: is_seqnum_sv.c lib${LIBNAME2}.so
	gcc -g $< -L${LIBDIR} -L${LIBDIR2} -I${LIBDIR} -l${LIBNAME} -l${LIBNAME2} -o $@

lib${LIBNAME2}.so: read_line.o
	gcc -g -shared read_line.o -o $@

read_line.o: read_line.c
	gcc -g -c -fPIC $^ -o $@

clean :
	rm -f ${FILES} *.o *.so