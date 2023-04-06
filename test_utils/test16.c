#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {

    time_t t1;

    time_t t2 = time( &t1 ) ;

    char * str1 = ctime( &t1 ) ;

    printf("The current time is %s", str1) ;



    struct timeval t3;

    int res = gettimeofday( &t3, NULL) ;

    char * str2 = ctime( &t3.tv_sec ) ;

    printf("The current time is %s", str2) ;


    struct tm t4;

    struct tm* pt4 = gmtime_r(&t3.tv_sec, &t4) ;

    struct tm t5;

    struct tm* pt5 = localtime_r(&t3.tv_sec, &t5) ;


    return 0;
}