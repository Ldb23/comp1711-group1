#include <stdio.h>
int main() {
    int a = 0;
    printf("[1] Select Banana\n");
    printf("[2] Select Apple\n");
    printf("[3] Select Watermelon\n");
    printf("[4] Select Pineapple\n");
    printf("[5] Select Orange\n");
    scanf("%d", &a);

    switch (a) {
        case 1: printf("Option 1: Banana has been selected\n");
        break;

        case 2: printf("Option 2: Apple has been selected\n");
        break;

        case 3: printf("Option 3: Watermelon has been selected\n");
        break;

        case 4: printf("Option 4: Pineapple has been selected\n");
        break;

        case 5: printf("Option 5: Orange has been selected\n");
        break;
        
        default: printf("That isn't an option!\n");
    }
}