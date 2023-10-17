#include <stdio.h>

int main() {
    // Initialises an array of 5 length
    int array[5] = {5, 10, 15, 20, 25};
    // Initialises a variable for the sum to be stored
    int sum = 0;
    // Initialises the variable i to loop through the array
    int i;
    // Starting at i=0 up to i=4, repeat the function in the curly braces
    for (i = 0; i < 5; i++) {
        sum += array[i];
    }

    printf("The sum of the array is: %d\n", sum);
}