#include <stdio.h>

int main() {
    // An array is declared
    int array[] = {5, 10, 15, 20, 25};

    // Stores the size of "array" in a variable named j
    int j = sizeof(array)/sizeof(array[0]);

    // Initialises an empty array to store the reversed array
    int reverseArray[] = {};

    // Initialises i to represent the current element id evaluated in the for loop
    int i;

    // Starting at number of array elements -1, loop through the array in reverse order until 0th element
    for (i = j-1 ; i >= 0 ; i--) {

        // Inserts the element at the end of the array into the element at the start of the reverseArray
        reverseArray[j-i-1] = array[i];
    }

    //Proof that array is reversed
    printf("%d\n", reverseArray[0]);
    printf("%d\n", reverseArray[1]);
    printf("%d\n", reverseArray[2]);
    printf("%d\n", reverseArray[3]);
    printf("%d\n", reverseArray[4]);

}