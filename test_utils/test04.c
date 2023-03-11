//  Use variadic function arguments

#include <stdio.h>
#include <stdarg.h>

int add_nums(int count, ...) 
{
    int result = 0;

    va_list args;
    
    va_start(args, count);
    
    for (int i = 0; i < count; ++i) {
    
        result += va_arg(args, int);
    }
    
    va_end(args);
    
    return result;
}



int main() {

    int num1 = add_nums(3, 8, 4, 5) ;

    int num2 = add_nums(4, 1, -1, 2, -2);

    printf("Numbers : num1 = %d, num2 = %d\n", num1, num2) ;

    return 0;
}