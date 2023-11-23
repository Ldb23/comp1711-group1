#include <stdio.h>

void reverseArray(int *arr, int length) {
    for(int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        // First element equal to last etc
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}