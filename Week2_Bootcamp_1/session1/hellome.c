#include <stdio.h>
int main(){
    char name[15]; // defines a character string called name containing up to 15 characters

    printf("Hello, please enter your name:");
    scanf("%s", name); // reads user input from keyboard and stores in the variable called name
    printf("Your name is %s\n", name); // prints the phrase with the name variable in place of %s
    
    return 0;
}