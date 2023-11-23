#include <stdio.h>

float calcArea(float radius) {
    return 3.14159 * radius * radius;
}

int main() {
    float area = calcArea(5.0);
    printf("The area of the circle is %.2f\n m^2", area);

    return 0;
}