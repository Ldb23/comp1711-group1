#include <stdio.h>
int main() {
    printf("Enter your mark: ");
    int mark = 0;
    scanf("%d", &mark);
    if (mark >= 70) {
        printf("Congratulations, you have passed with distinction!\n");
    } else if (mark > 50) {
        printf("Congratulations, you have passed!\n");
    } else {
        printf("You have failed!");
    }
}