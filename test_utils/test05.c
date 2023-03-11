#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10


void process_sum(int* arr, int count) ;
void process_min(int* arr, int count) ;
void process_max(int* arr, int count) ;
void process_sort(int* arr, int count) ;
void process_print(int* arr, int count) ;


int main() {

    printf("Enter the size of array:\n");

    int count;

    scanf("%d", &count) ;

    int* arr = malloc( count * sizeof(int) ) ;

    if (arr == 0) {

        fprintf(stderr, "%s", "Allocation error!\n");
        exit(EXIT_FAILURE) ;
    } 


    printf("Enter %d numbers:\n", count);

    for (int i = 0; i < count; ++i) {

        scanf("%d", &arr[i]) ;
    }

    printf( "Enter operation [sum, max, min, sort]:\n") ;

    char str[BUF_SIZE];

    int res = scanf("%5s", str);

    if (res == EOF) {

        fprintf(stderr, "%s", "Read command error!\n");
        exit(EXIT_FAILURE) ;
    }

    int command_len = strlen(str) ;

    printf("Command = \"%s\", length = %d\n", str, command_len) ;


    if ( strcmp( str, "sum") == 0 ) {

        process_sum( arr, count);
    }
    else if ( strcmp( str, "min") == 0 ) {
        
        process_min( arr, count ) ;
    }
    else if ( strcmp( str, "max") == 0 ) {

        process_max( arr, count ) ;
    }
    else if ( strcmp( str, "sort") == 0) {

        process_sort( arr, count) ;
        process_print( arr, count) ;
    }
    else if ( strcmp( str, "all") == 0) {

        process_sum( arr, count);
        process_min( arr, count ) ;
        process_max( arr, count ) ;
        process_sort( arr, count) ;
        process_print( arr, count) ;
    }

    free(arr) ;

    return EXIT_SUCCESS;
}

void process_sum(int* arr, int count) {

    int total = 0;

    for (int i = 0; i < count; ++i) {

        total += arr[i];
    }

    printf("Sum = %d\n", total) ;
}

void process_min(int* arr, int count) {

    int result = arr[0];

    for (int i = 1; i < count ; ++i) {

        if (arr[i] < result ) {
            result = arr[i] ;
        }
    }

    printf("Min = %d\n", result) ;
}

void process_max(int* arr, int count) {

    int result = arr[0];

    for (int i = 1; i < count ; ++i) {

        if (arr[i] > result ) {
            result = arr[i] ;
        }
    }

    printf("Max = %d\n", result) ;
}


int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*) a;
    int arg2 = *(const int*) b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

void process_sort(int* arr, int count) {

    qsort(arr, count, sizeof(int), compare_ints);
}

void process_print(int* arr, int count) {

    for (int i = 0; i < count; ++i) {

        printf("%d ", arr[i] ) ;
    }

    printf("\n") ;
}