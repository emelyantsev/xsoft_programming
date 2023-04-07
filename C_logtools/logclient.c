#include "logtools.h"

int main( int argc, char *argv[] ) {

    struct sockaddr_in svaddr;
    struct Message msg;
    size_t msgLen = sizeof(struct Message);

    int sfd;

    if (argc < 4 || strcmp(argv[1], "--help") == 0) {

        fprintf(stderr, "Usage: %s ip_address position char\n", argv[0] ) ;
        exit(1);
    }

    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sfd == -1) {

        fprintf(stderr, "Error socket %s\n", strerror(errno) ) ;
        exit(1);
    }

    memset( &svaddr, 0, sizeof(struct sockaddr_in));
    svaddr.sin_family = AF_INET;
    svaddr.sin_port = htons(PORT_NUM);

    if ( inet_pton(AF_INET, argv[1], &svaddr.sin_addr) <= 0 ) {

        fprintf(stderr, "inet_pton failed for address %s\n", argv[1]) ;
        exit(1);
    }

    msg.c = argv[3][0];
    msg.pos = atoi(argv[2]);

    if ( sendto(sfd, &msg, msgLen, 0, (struct sockaddr *) &svaddr, sizeof(struct sockaddr_in)) != msgLen) {

        fprintf(stderr, "Error sendto %s\n", strerror(errno)) ;
        exit(1);
    }
    else {

        printf("Send OK: Position = %d, symbol = %c\n", msg.pos, msg.c) ;
    }

    close(sfd);

    return EXIT_SUCCESS;
}