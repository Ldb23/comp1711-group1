// Example function

#include <stdio.h>
// How we define a function

// *int sum* declares the type of value that the function returns
// Input parameters a and b, allocated to a and b in order

int sum (int a, int b) { // Local variables only, not globally scoped

    int answer; // Initializes answer variable

    answer = a + b;// Performs calc, and allocates result to the local variable "answer"

    return answer; // Returns the value of the answer in the function call in the main program
}

// How we call a function

int main() {
    int y = 2; // Defines a variable y for input into our sum function
    int z = sum(5, y); // calling our new function "sum" with inputs of 5(for a) and y(for b)

    printf("The sum of 5 and %d is %d\n", y, z);
}
