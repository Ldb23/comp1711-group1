#include <stdio.h>
int main() {
    int num;
    printf("Please input your number: ");
    scanf("%d", &num);
    printf("The number to be checked is: %d\n", num);

    if (num % 5 == 0 && num % 4 == 0) {
        printf("%d is divisble by both 5 and 4\n", num);
    } else if (num % 5 == 0) {
        printf("%d is divisble by 5\n", num);
    } else if 
        (num % 4 == 0) {
        printf("%d is divisible by 4\n", num);
    } else {
        printf("%d is not divisible by 4 or 5\n", num);
    }
}