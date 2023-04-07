#ifndef	_LOG_TOOLS_H
#define	_LOG_TOOLS_H	1

#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include <assert.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define FILENAME "history.log"
#define FORMAT_SIZE 6

#define PORT_NUM 4577

#define MAX_EVENTS     1
#define BUFSIZE 16 

struct Record {

    struct in_addr host;
    in_port_t port;
    time_t arrival_time;
    char c;
    int pos;
};


struct Message {

    int pos;
    char c;
};


struct Header {

    char version[FORMAT_SIZE];
    int size;
};


#endif // _LOG_TOOLS_H