#include <stdio.h> 
int main() {
    int a;
    for (a = 0; a < 20; a++) {
        if (a % 2 != 0) { // Prints only if the remainder of a/2 does not equal 0
            printf("a is equal to %d\n", a);
        }
    }
    return(0);
}