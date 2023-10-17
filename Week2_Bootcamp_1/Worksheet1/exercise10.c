#include <stdio.h>
int main() {
    printf("Enter the amount you'd like to borrow: ");
    int borrow;
    scanf("%d", &borrow);

    printf("Enter the amount of years you'd like to pay it back: ");
    int years;
    scanf("%d", &years);

    printf("Enter your desired percentage interest per annum: ");
    int interestRate;
    scanf("%d", &interestRate);

    int i;

    float interest = borrow;

    for (i = 1; i <= years; i++) {
        interest = ((interest/100) * interestRate) + interest;
    }

    printf("Your total repayment sum is £%.2f\n", interest);

    return 0;
}