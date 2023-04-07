#include "logtools.h" 


static volatile sig_atomic_t shouldStop = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

volatile char str[BUFSIZE + 1];


void sigHandler(int) ;

void* threadFunc(void* ) ;

int timeval_subtract (struct timeval* result, struct timeval* x, struct timeval* y) ;


int main( int argc, char *argv[] ) {

    int sfd;
    struct sockaddr_in svaddr, claddr;

    struct Message msg;

    ssize_t numBytes;
    socklen_t len = sizeof(struct sockaddr_in) ;

    char claddrStr[INET_ADDRSTRLEN];

    struct sigaction sa;

    int lfd;
    struct Record record;


    struct timeval t1, t2, t3;

    int epfd;
    struct epoll_event ev;
    struct epoll_event evlist[MAX_EVENTS];
    int ready;


    pthread_t th_1;
    int s;
    
    // Signals setup

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0; // *add comment here
    sa.sa_handler = sigHandler;
    
    if ( sigaction(SIGINT, &sa, NULL) == -1 ) {

        fprintf(stderr, "Error setting signal handler %s\n", strerror(errno) ) ;
        exit(1);
    }

    // Socket setup

    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sfd == -1) {

        fprintf(stderr, "Error socket %s\n", strerror(errno) ) ;
        exit(1);
    }

    memset(&svaddr, 0, sizeof(struct sockaddr_in));
    svaddr.sin_family = AF_INET;
    svaddr.sin_addr.s_addr = INADDR_ANY;                   
    svaddr.sin_port = htons(PORT_NUM);

    if ( bind(sfd, (struct sockaddr *) &svaddr, sizeof(struct sockaddr_in) ) == -1) {

        fprintf(stderr, "Error bind %s\n", strerror(errno) ) ;
        exit(1);
    }

    // Log file setup

    lfd = open(FILENAME, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR ) ;

    if (lfd == -1) {

        fprintf(stderr, "Error opening file %s %s\n", FILENAME, strerror(errno) ) ;
        exit(1);
    }

    // Epoll setup

    epfd = epoll_create(MAX_EVENTS);

    if (epfd == -1) {

        fprintf(stderr, "Error epoll_create %s\n", strerror(errno) ) ;
        exit(1);
    }

    ev.events = EPOLLIN;
    ev.data.fd = sfd;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &ev) == -1) {

        fprintf(stderr, "Error epoll_ctl %s\n", strerror(errno) ) ;
        exit(1);
    }


    // Initalize common string

    for (int i = 0; i < BUFSIZE; ++i) {
        str[i] = 'A';
    }

    str[BUFSIZE] ='\0';


    // Launch printing thread

    s = pthread_create(&th_1, NULL, threadFunc, NULL );

    if (s != 0) {

        fprintf(stderr, "Error pthread_create %s\n", strerror(errno) ) ;
        exit(1);
    }


    // Main loop

    while ( shouldStop == 0 )  {

        int res_ept0 = gettimeofday( &t1, NULL) ;


        ready = epoll_wait(epfd, evlist, MAX_EVENTS, -1);

            
        int res_ept1 = gettimeofday( &t2, NULL) ;    
        timeval_subtract(&t3, &t2, &t1);
        printf("Epoll_wait took %ld s %ld us\n", t3.tv_sec, t3.tv_usec) ;


        if (ready == -1) {

            if (errno == EINTR) {

                continue;               /* Restart if interrupted by signal */
            } 
            else {

                fprintf(stderr, "Error epoll_wait %s\n", strerror(errno) ) ;
                break;
            }
        }

        if ( evlist[0].events & EPOLLERR ) {

            fprintf(stderr, "Got error event for dgram socket \n" ) ;
            break;
        }

        else if ( evlist[0].events & EPOLLIN  ) {

            assert( evlist[0].data.fd == sfd ) ;


            printf("Before recv, num bytes = %ld, shouldStop = %d\n", numBytes, shouldStop);
            int res1 = gettimeofday( &t1, NULL) ;

            numBytes = recvfrom(sfd, &msg, sizeof(struct Message), 0, (struct sockaddr *) &claddr, &len );


            int res2 = gettimeofday( &t2, NULL) ;
            printf("After recv, num bytes = %ld, shouldStop = %d\n", numBytes, shouldStop);
            
            timeval_subtract(&t3, &t2, &t1);
            printf("Recvfrom took %ld s %ld us\n", t3.tv_sec, t3.tv_usec) ;



            if (numBytes == -1) {

                if (errno == EINTR) {
                    fprintf( stderr, "Error recvfrom %s\n", strerror(errno) ) ;
                    continue;
                }
                else {
                    fprintf( stderr, "Error recvfrom %s\n", strerror(errno) ) ;
                    break;
                }

            }

            if (inet_ntop(AF_INET, &claddr.sin_addr, claddrStr, INET_ADDRSTRLEN) == NULL) {

                fprintf( stderr, "Couldn't convert client address to string\n");
            }
            else {

                printf("Server received %ld bytes from (%s, %u)\n", numBytes, claddrStr, ntohs(claddr.sin_port)) ;
                printf("Position = %d, symbol = %c\n", msg.pos, msg.c) ;
            }

            record.arrival_time = time( NULL ) ;
            record.host = claddr.sin_addr;
            record.port = claddr.sin_port;
            record.c = msg.c;
            record.pos = msg.pos;


            s = pthread_mutex_lock( &mtx );

            if (s != 0) {

                fprintf(stderr, "Error pthread_mutex_lock %s\n", strerror(errno) ) ;
                exit(1);
            }

            str[ msg.pos % BUFSIZE] = msg.c ;

            s = pthread_mutex_unlock(&mtx);

            if (s != 0) {

                fprintf(stderr, "Error pthread_mutex_unlock %s\n", strerror(errno) ) ;
                exit(1);
            }


            int count = write(lfd, &record, sizeof(struct Record)) ;

            if (count != sizeof(struct Record) ) {
                
                fprintf(stderr, "Error write file %s %s\n", FILENAME, strerror(errno) ) ;
                exit(1);
            }
            
        }

    }

    // Graceful shutdown

    printf("Graceful shutdown\n") ;

    if ( close(lfd) == -1) {

        fprintf(stderr, "Error close file %s %s\n", FILENAME, strerror(errno) ) ;
        exit(1);
    }

    s = pthread_join(th_1, NULL);

    if (s != 0) {

        fprintf(stderr, "Error pthread_join %s\n", strerror(errno) ) ;
        exit(1);
    }


    return EXIT_SUCCESS;
}


int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {

    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }

  if (x->tv_usec - y->tv_usec > 1000000) {

    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

void sigHandler(int sig) 
{
    shouldStop = 1 ;
}

void* threadFunc(void* arg) {

    while (shouldStop == 0) {

        int s = pthread_mutex_lock( &mtx );

        if (s != 0) {

            fprintf(stderr, "Error pthread_mutex_lock %s\n", strerror(errno) ) ;
            exit(1);
        }

        printf("STR : %*s\n", BUFSIZE, str) ;

        s = pthread_mutex_unlock(&mtx);

        if (s != 0) {

            fprintf(stderr, "Error pthread_mutex_unlock %s\n", strerror(errno) ) ;
            exit(1);
        }

        sleep(3);
    }

    printf("Print thread gracefully shutdown\n") ;
}