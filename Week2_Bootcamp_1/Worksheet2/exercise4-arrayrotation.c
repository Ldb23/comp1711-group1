#include <stdio.h>
int main() {
    // An array is declared
    int array[] = {5, 10, 15, 20, 25};
    
    int rotatedArray[] = {};

    int j = sizeof(array)/sizeof(array[0]);

    rotatedArray[0] = array[j];


    for (int i = 1; i < j; i++) {
        int temp = array[j - 1];
        rotatedArray[i] = array[i - 1];
        rotatedArray[0] = temp;
    }


    for (int i = 0; i < j; i++) {
    printf("%d ", rotatedArray[i]);
    }

}
