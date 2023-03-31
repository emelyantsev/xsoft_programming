#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
  char *a;
  char *b;

  a = malloc( 200 );
  b = malloc( 64 );

  printf("a = %p, b = %p, b-a = %ld\n\n", a, b, b-a);

  strcpy(a, argv[1]);

  printf("a = %s (%lu)\n", a, strlen(a));
  printf("b = %s (%lu)\n", b, strlen(b));

  free(a);
  free(b);

  return 0;
}