#include <stdio.h>

int main() {
    printf("What is the current temperature in Fahrenheit? ");
    int faren;
    scanf("%d", &faren);

    int celsius = (faren - 32) / 1.8;

    printf("The temperature right now is %d degrees celsius\n", celsius);
}