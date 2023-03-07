#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_MAX 255

int port, portlow, porthigh;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *scan(void *arg)
{
  int sd;
  struct sockaddr_in servaddr;
  struct servent *srvport;
  struct hostent* hp;

  char *argv1 = (char*) arg;
  
  hp = gethostbyname(argv1);

  if (hp == NULL) {
    herror("gethostbyname() failed");
    exit(-1);
  }

  bzero( &servaddr, sizeof(servaddr) );

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr = *((struct in_addr *) hp->h_addr );

  while ( 1 )
  {

    pthread_mutex_lock(&lock);

    int current_port = port;
    ++port;

    pthread_mutex_unlock(&lock);

    if (current_port > porthigh) {
      break;
    }
    
    pid_t thread_id = gettid();

    printf("Thread with id %d starting to scan port %d\n", thread_id, current_port) ;
    fflush(stdout);

    servaddr.sin_port = htons(current_port);

    if ( (sd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket() failed");
      exit(-1);
    }

    
            
    if (connect(sd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == 0) {

      srvport = getservbyport(htons(current_port), "tcp");
      
      if (srvport == NULL)
        printf("Open: %d (unknown)\n", current_port);
      else
        printf("Open: %d (%s)\n", current_port, srvport->s_name);
      
      fflush(stdout);
    }

    close(sd);

  }
}

int main(int argc, char *argv[])
{

  pthread_t threads[THREADS_MAX];
  
  int thread_num;
  int i;
  
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <address> <portlow> <porthigh> <num threads>\n", argv[0]);
    exit(-1);
  }
  
  thread_num = atoi(argv[4]);
  
  if (thread_num > THREADS_MAX)
    fprintf(stderr, "too many threads requested");

  portlow  = atoi(argv[2]);
  porthigh = atoi(argv[3]);
  port     = portlow;
  
  fprintf(stderr, "Running scan...\n");
  
  for (i = 0; i < thread_num; i++)

    if (pthread_create( &threads[i], NULL, scan, argv[1]) != 0)
      fprintf(stderr, "error creating thread");

  for (i = 0; i < thread_num; i++)
    pthread_join(threads[i], NULL);

  return 0;
}