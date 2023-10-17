#include <stdio.h>
int main() {
    float side_a;
    float side_b;
    float area;

    printf("Enter the length of side a in metres: ");
    scanf("%f", &side_a);
    printf("Enter the length of side b in metres: ");
    scanf("%f", &side_b);
    
    area = side_a * side_b;

    printf("The area of your rectangle is: %.2f\n", area);
}