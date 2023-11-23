#include <stdio.h>

float sphVolume(float radius) {
    return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
};

int main() {
    float volume = sphVolume(5.0);
    printf("The volume of the sphere is: %.2f m^3\n", volume);
}