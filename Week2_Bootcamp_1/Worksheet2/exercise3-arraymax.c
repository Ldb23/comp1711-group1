#include <stdio.h>

int main() {
    // An array is declared
    int array[] = {5, 10, 15, 20, 25};

    // Stores the size of "array" in a variable named j
    int j = sizeof(array)/sizeof(array[0]);

    // Initialises an empty array to store the reversed array
    int maxElement = 0;

    // Initialises i to represent the current element id evaluated in the for loop
    int i;

    for (i = 0; i < j; i++) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        };
    }

    printf("The largest element in the array is: %d\n", maxElement);
}