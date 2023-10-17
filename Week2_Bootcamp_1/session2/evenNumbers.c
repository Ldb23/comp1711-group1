#include <stdio.h> 
int main() {
    int a = 20;
    while(a > 0) {
        if (a % 2 == 0) {
            printf("a is equal to %d\n", a);
        }
        a--;
    }
    return 0;
}
