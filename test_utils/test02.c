#include <stdio.h>
#include <string.h>


int main() {

    const char* msg1 = "Hi";
    const char* msg2 = "world";


    printf("%s, %s!\n", msg1, msg2);

    printf("len(msg1) = %ld, len(msg2) = %ld\n", strlen(msg1), strlen(msg2) ); 


    size_t len2 = strlen(msg2) ;


    for (int i = 0; i < len2; ++i) {

        printf("\"%c\" ", msg2[i]);
    }

    printf("\n") ;


    return 0;
}