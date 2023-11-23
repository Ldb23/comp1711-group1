#include <stdio.h>

char* concatStrings(char *str1, char *str2) {
    int len1 = 0;

    // Finds the length of first string
    while (str1[len1] != '\0') {
        len1++;
    }
    int len2 = 0;

    // Finds the length of second string
    while (str2[len2] != '\0') {
        len2++;
    }

    // Initialise an empty string for the result
    static char result[100];

    // Copy str1 into result
    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    // Append str2 onto the end of result
    for (int i = 0; i < len2; i++) {
        result[len1 + i] = str2[i];
    }

    // Null-terminate result at the end character
    result[len1 + len2] = '\0';

    return result;

}

int main() {
    char *str1 = "Hello, ";
    char *str2 = "world!";
    char *newString = concatStrings(str1, str2);

    printf("Concatenated string: %s\n", newString);
    return 0; 
}
