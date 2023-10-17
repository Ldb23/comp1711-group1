#include <stdio.h>

int main() {
    printf("Please enter an integer!: ");

    int a;

    scanf("%d", &a);

    if (a % 2 == 0) {
        printf("The number %d is even\n", a); 
        
        } else {
            printf("The number %d is odd\n", a);
        }
    }