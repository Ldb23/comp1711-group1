#include <stdio.h>

int main() {
    int beans;
    float cheese;
    double pasta;
    char fork;

    printf("Size of int: %zu bytes\n", sizeof(beans));
    printf("Size of float: %zu bytes\n", sizeof(cheese));
    printf("Size of pasta: %zu bytes\n", sizeof(pasta));
    printf("Size of fork: %zu bytes\n", sizeof(fork));
}