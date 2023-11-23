#include <stdio.h>
#include <stdbool.h>
int main() {
    int number;
    bool isTerminationValue;

    do {
        printf("Enter a number between 0 and 100 (-1 to exit): ");
        scanf("%d", &number);

        isTerminationValue = (number == -1);

        // || represents "or"
        if ((number >=0 && number <= 100) || isTerminationValue) {
            printf("The number is valid.\n");
        } else {
            printf("The number is out of range.\n");
        }
    } while (!isTerminationValue);

    return 0;





}