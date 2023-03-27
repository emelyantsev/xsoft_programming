#define _DEFAULT_SOURCE

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>

#include <math.h>

int main() {

    float r = 4.55;

    float S = M_PI * r * r;

    printf("Square is %f\n", S) ;
    printf("Square is %10f\n", S) ;
    printf("Square is %.3f\n", S) ;
    printf("Square is %e\n", S) ;
    printf("Square is %.3E\n", S) ;

    printf("Address of r = %p\n", &r) ;
    printf("Address of S = %p\n", &S) ;

    return 0;
}