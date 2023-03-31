#include <stdio.h>

int main( int argc, char *argv[] )
{

  int a = 3;
  char *str = "Aleksey";
  int b = 555;

  printf( argv[1] );


  printf("\n&a = %p , &b = %p, str = %p\n", &a, &b, &str) ;

  return 0;
}