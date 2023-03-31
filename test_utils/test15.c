#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {

    int x =  -1598962732;  //0xa0b1c3d4;

    printf("x = %d\n", x) ;
    printf("x = %u\n", x) ;


    unsigned char byte1, byte2, byte3, byte4;

    byte1 = ( x & 0xff000000 ) >> 24;
    byte2 = ( x & 0x00ff0000 ) >> 16;
    byte3 = ( x & 0x0000ff00 ) >> 8;
    byte4 = ( x & 0x000000ff );


    unsigned char * pnum = malloc(sizeof(unsigned char) * 4) ;

    pnum[0] = byte4;
    pnum[1] = byte3;
    pnum[2] = byte2;
    pnum[3] = byte1;

    int y = *( (int*) pnum) ;

    printf("y = %d\n", y) ;
    printf("y = %u\n", y) ;

    assert( x == y);


    for (int i = 0; i < 4; ++i) {

        unsigned char * ptr = pnum + i;

        printf("ptr = %p , *ptr = %#hhx\n", ptr, *ptr) ;
    }

    free(pnum) ;

    return 0;
}