#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inputs are const because their values do not change
// Pointers are denoted by * (tells you where to find them)
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main() {
    char record[21] = "2023-09-01,07:30,300"; // hard coded for now, but in future will read from the csv file
    char date[11]; // Empty character array
    char time[6]; // Empty character array
    char steps[10];  // Large enough to hold a typical step count as a string

    int stepsint;
    
    // record input identifies which string in the array, and the "," is (where it should be split) the delimiter
    // Outputs useful date time and steps data
    tokeniseRecord(record, ",", date, time, steps);
    
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Steps: %s\n", steps);

    // Function called atoi to convert the steps to an integer
    stepsint = atoi(steps); 
    printf("Steps as an integer: %d\n", stepsint);
    
    return 0;
}