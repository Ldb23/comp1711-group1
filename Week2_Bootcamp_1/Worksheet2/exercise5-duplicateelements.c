#include <stdio.h>
int main() {
    int array[] = {1, 2, 3, 4, 5, 5, 7, 2};

    // Calculates number of elements in the array
    int length = sizeof(array)/sizeof(array[0]);

    // Some text
    printf("Here's a list of duplicate elements from your array: \n");

    // For loop which cycles through all elements in the array
    for (int i = 0; i < length; i++) {

        // For loop which cycles through all elements in the array starting from the element next to i
        for (int j = i + 1; j < length; j++) {

            // Compares the array element to the elements after (as the elements before have already been compared in the last iteration)
            if(array[i] == array[j])

            // Prints the element which is a duplicate
            printf("%d\n", array[j]);
        }
    }
}