#include <stdio.h>

int str_len(char *str) {
    int length = 0;
    // While string character does not equal end character (\0)
    while (*str != '\0') {
        // Increment length counter
        length++;
        // Move onto next character in string
        str++;
    }
    return length;
}

int main() {
    int length = str_len("hiya");
    printf("The length of the string is: %d\n", length);
    return 0;
}