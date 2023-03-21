#include <stdio.h>
#include <stdlib.h>


#define DOREAD ( 1 )
#define DOWRITE ( 1 << 1 ) 
#define DOREADWRITE ( DOREAD | DOWRITE  )


void doWork(int options) ;


int main() {


    doWork(DOREAD);
    doWork(DOWRITE);
    doWork(DOREADWRITE);
    doWork(DOREAD | DOWRITE) ;
    
    return EXIT_SUCCESS;
}




void doWork(int options) {

    if (options & DOREAD) {

        printf("Do some reading\n") ;
    }

    if ( options & DOWRITE ) {

        printf("Do some writing\n") ;
    }

    printf("-----------------\n") ;
}