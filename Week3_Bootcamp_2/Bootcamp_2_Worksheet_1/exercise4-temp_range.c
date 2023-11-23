#include <stdio.h>
int main() {
    int temp = 0;
    printf("Enter your Temperature in celsius: ");
    scanf("%d", &temp);
    if (temp > 40) {
        printf("Too hot!\n");
    } else if (temp < -10) {
        printf("Too cold!\n");
    } else {
        printf("The Temperature you provided is within range.");
    }
}