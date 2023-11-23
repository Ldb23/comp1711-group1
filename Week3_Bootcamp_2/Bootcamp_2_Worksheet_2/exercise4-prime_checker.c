#include <stdio.h>

int isPrime(int numtocheck) {
    if (numtocheck <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= numtocheck; i++) {
        if (numtocheck % i == 0) {
            return 0;
        }
    }
    return 1;
    
}

int main() {
    int number = 7;
    if (isPrime(number)) {
        printf("%d is a prime number\n", number);
    } else {
        printf("%d is not a prime number\n", number);
    }

}