#include <stdio.h>
int main() {
    int a [10];
    int count;

    // Populate an array
    for (count = 0; count < 10; count++) {
        a[count] = count * 10 + count; // Populate the count array with 0, 11, 22, 33 etc
    }
    printf ("The first and second elements are %d and %d\n", a[0], a[1]);
    printf ("Or, via pointers, %d and %d\n", *a, *(a+1));
    return 0;
}
