#include <stdio.h>

int main() {
    char x = 'X';
    char y = 'Y';
    char temp;

    //Introduce a third temporary variable
    temp = x;
    x = y;
    y = temp;


    printf("x = %c\n", x);
    printf("y = %c\n", y);
    }