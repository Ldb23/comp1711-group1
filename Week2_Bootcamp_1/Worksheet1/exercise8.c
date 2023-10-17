#include <stdio.h>

int main(){
    printf("Please input an integer: ");
    int num;
    int fact = 1; // Need to initialise with a value, or random numbers will generate from previous allocation
    scanf("%d", &num);
    int a;
    for (a = 1; a <= num; a++) {
        fact = fact*a;
    }
    printf("The factorial of %d is %d\n", num, fact);
}