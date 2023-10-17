#include <stdio.h>
int main() {
    int num;
    printf("Please input your number: ");
    scanf("%d", &num);
    printf("The number to be checked is: %d\n", num);

    if (num < 0) {
        printf("%d is negative", num);
    } else if (num == 0) {
        printf("%d is zero, so has no sign", num);
    } else {
        printf("%d is positive\n", num);
    }
}