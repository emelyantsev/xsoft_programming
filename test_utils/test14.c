#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    char str[] = "\x00\xab\xef\x01" ;

    size_t len = strlen( str ) ;

    printf("Len is %lu\n", len) ;


    unsigned char * ptr = &str[0];
     

    while ( true ) {

        printf("Char is %hhu\n", *ptr) ;
        ++ptr;
    }


    return 0;
}