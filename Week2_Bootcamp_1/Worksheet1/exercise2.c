#include <stdio.h>

int main() {
    int a;
    int b;
    printf("Please input an integer: ");
    scanf("%d", &a); // scanf requires pointers to actually change the variable, i.e. &
    printf("Please input another integer: ");
    scanf("%d", &b); // scanf requires pointers to actually change the variable, i.e. &
    int c = a + b;
    printf("The sum of your two integers is: %d\n", c);
}