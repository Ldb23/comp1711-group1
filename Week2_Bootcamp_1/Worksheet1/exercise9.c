#include <stdio.h>

int main() {
    float SOL = 2.998e8;
    int secondsinDay = 86400;
    float distperDay = SOL * secondsinDay;
    int days;

    printf("Please tell, how many days has your light been travelling?: ");
    scanf("%d", &days);
    float travelledKm = (days * distperDay)/1000;

    // 4.3e denotes 4 significant figures of which 3 follow the decimal place, and scientific notation

    printf("Wow, your light has travelled %4.3e km since it started %d days ago!\n", travelledKm, days);    
}