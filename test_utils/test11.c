#include <stdio.h>

union S {
	int n;
	char b;
} x;

int main() {

	x.n = 0x4142;

	if (x.b == 0x42) {
		
        printf("Little Endian\n");
	}
	else {

		printf("Big Endian\n");
	}


    union S y;

    y.n = 0x01A09BFF;

    printf("Size is %lu\n", sizeof(y) ) ;

    printf( "%hhx\n", y.b ) ;

    char * ptr = (char *) &y;

    for (int i = 0; i < 4; ++i) {

        printf( "%hhX\n", *(ptr+i) ) ;
    }
 
    return 0;
}