#include "logtools.h"

int main() {

    int lfd;
    struct Record record;

    lfd = open(FILENAME, O_RDONLY) ;

    if (lfd == -1) {

        fprintf(stderr, "Error opening file %s %s\n", FILENAME, strerror(errno) ) ;
        exit(1);
    }

    char claddrStr[INET_ADDRSTRLEN];

    while ( read(lfd, &record, sizeof(struct Record) ) == sizeof(struct Record) ) {

        if ( inet_ntop(AF_INET, &record.host, claddrStr, INET_ADDRSTRLEN) == NULL ) {
            continue;
        }  

        printf("IP = %s, Port = %hu, Pos = %d, Char = %c Time = %s", 
            claddrStr, ntohs(record.port), record.pos, record.c, ctime( &record.arrival_time )  );
    
    }

    if ( close(lfd) == -1) {

        fprintf(stderr, "Error close file %s %s\n", FILENAME, strerror(errno) ) ;
        exit(1);
    }

    return EXIT_SUCCESS;

}