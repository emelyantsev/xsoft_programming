#include <stdio.h>
#include <stdlib.h>


int main( int argc, char* argv[] ) {


    if (argc != 3) {

        printf("Usage: test03 seed count\n") ;
        exit(13);
    }

    int seed = atoi(argv[1]) ;
    int count = atoi(argv[2]) ;

    srandom( seed ) ;


    long long total = 0;


    for (int i = 0; i < count; ++i) {

        int x = random();

        printf("Generated int = %d\n", x) ;
        total += x;
    }

    printf("Total sum = %lld\n", total) ;


    return 0;
}