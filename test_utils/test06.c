#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {

    const char* password = "19861986" ;
    const char* salt = "$6$gmsanNMSBe8IARpN$" ;

    char* encrypted_pass = crypt( password, salt ) ;

    if (encrypted_pass != NULL ) {

        printf( "%s\n", encrypted_pass ) ;
    }
    else {

        if (errno == EINVAL) {
            printf("ERROR: salt has the wrong format.\n") ;
        }
    }

    return 0;
}