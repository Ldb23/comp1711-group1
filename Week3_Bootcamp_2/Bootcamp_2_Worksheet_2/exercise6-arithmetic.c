#include <stdio.h>

float calculator(float a, float b, char c) {
    switch(c) {
        case '+': return a + b;
        break;
        case '-': return a - b;
        break;
        case '/': if(b != 0) return a / b;
        break;
        case '*': return a * b;
        break;
        default: printf("Invalid input");
    }
    return 0;
}

int main() {
    float result = calculator(5, 3, '+');
    printf("The result is %.1f\n", result);
    return 0;
}