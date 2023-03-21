all : libcommon.a libsockets.a

libcommon.a : error_funcions.o get_num.o become_daemon.o
	ar rcs libcommon.a error_functions.o get_num.o become_daemon.o

error_funcions.o : ename.c.inc error_functions.c
	gcc -c error_functions.c -o error_functions.o -g

get_num.o : get_num.c	
	gcc -c get_num.c -o get_num.o -g

ename.c.inc :
	sh Build_ename.sh > ename.c.inc
	echo 1>&2 "ename.c.inc built"

become_daemon.o : become_daemon.c
	gcc -c $^ -o $@ -g

libsockets.a : inet_sockets.o unix_sockets.o
	ar rcs $@ $^

inet_sockets.o : inet_sockets.c
	gcc -c $^ -o $@ -g

unix_sockets.o : unix_sockets.c
	gcc -c $^ -o $@ -g

clean :
	rm -f *.o *.a