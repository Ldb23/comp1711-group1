#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char choice;
char line[buffer_size];
char filename[buffer_size];
int lineCount = 0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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




// Complete the main function
int main() {

    do {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Input filename: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            } else {
                printf("File successfully loaded.\n");
            }
            break;

        case 'B':
        case 'b':
            if (input) {
                // While lines have some text, increment the lineCount
                while (fgets(line, buffer_size, input) != NULL) {
                    lineCount += 1;
                }
                printf("Total records: %d\n", lineCount);
            }else{
                printf("Error: File not open\n");
            };
            break;

        case 'C':
        case 'c':
            break;
        case 'D':
        case 'd':
            break;
        case 'E':
        case 'e':
            break;
        case 'F':
        case 'f':
            break;
        case 'Q':
        case 'q':
            return 0;
            break;
        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
        } while (choice != 'Q' && choice != 'q');

        return 0;
}









