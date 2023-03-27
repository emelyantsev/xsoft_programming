#include <stdio.h>
#include <wchar.h>



struct S1 {

    int x;
    char c;
    long long l;
};


union U1 {

    int x;
    char c;
    //long long l;
};


int main() {

    int x = 12;
    long long y = 9;

    printf("Size of x = %lu\n", sizeof(x) ) ;

    printf("Size of y = %lu\n", sizeof(y) ) ;

    float pf = 3.14;
    double pd = 3.14;

    printf("Size of pf = %lu\n", sizeof(float) ) ;

    printf("Size of pd = %lu\n", sizeof(pd) ) ;


    char c = 'A';
    wchar_t w = 'B'; 

    printf("Size of c = %lu\n", sizeof(c) ) ;

    printf("Size of w = %lu\n", sizeof(w) ) ;



    printf("Size of S1 = %lu\n", sizeof(struct S1));
    printf("Size of U1 = %lu\n", sizeof(union U1));



    char arr[12];

    char* str = "I am" ;


    printf("Size of arr = %lu\n", sizeof(arr));
    printf("Size of str = %lu\n", sizeof(str));


    return 0;
}