#include <stdio.h>
#include <string.h>

int main() {
 
    char input[100];
    char password[10] = "hello";
 
    printf ("\nEnter your password: ");
    scanf("%100s", &input);
    
    printf("\nYour string is :");
    printf(input);

    if (strcmp(password, input ) == 0) {

        printf("\nYour password is correct\n");
    }
    else
        {
        printf("\nPassword doesn't match\n");
    }
}