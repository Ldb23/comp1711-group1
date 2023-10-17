#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846264338327950

int main() {
    int radius;
    printf("Please input the radius of your circle: ");
    scanf("%d", &radius);
    float area = radius * radius * PI;
    printf("The area of your circle is: %f m2\n", area);
}