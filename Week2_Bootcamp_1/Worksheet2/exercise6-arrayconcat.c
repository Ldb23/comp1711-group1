#include <stdio.h>
int main() {

    // Declare an array, and calculate its size
    int a1[] = {1, 2, 3};
    int n1 = sizeof(a1)/sizeof(a1[0]);

    // Declare another array, and calculate its size
    int a2[] = {4, 5, 6};
    int n2 = sizeof(a2)/sizeof(a2[0]);

    // Initialise a third array for the concatenated arrays, and calculate it's length using the previous length variables
    int n3 = n2 + n1;
    int a3[n3];

    // Loop through the first array and set the first three elements of the cated array to the same
    for (int i = 0; i < n1; i++) {
        a3[i] = a1[i];
    }

    // Loop through the second array, countring through j values (up to number of elements in the catted array)
    // Append the elements 3-5(j) with elements 0-2(i) in the second array.
    for (int i = 0, j = n1; j < n3; i++, j++) {
        a3[j] = a2[i];
    }

    // Print the elemements in the cated array
    printf("The concatenated array is: \n");
    for (int i = 0; i < n3; i++){
        printf("%d ", a3[i]);
    }

    printf("\n");
    return 0;
}