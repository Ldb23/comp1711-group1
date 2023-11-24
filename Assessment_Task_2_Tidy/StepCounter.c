#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Definition of global variables and structured array

char choice; // To hold the users case selection.
char line[buffer_size]; // To define the max size of a given line in the file to be opened.
char filename[buffer_size]; // To define the max size of the file name to be opened.
int lineCount = 0; // Variable initialized to count the number of lines in a file.
#define MAX_RECORDS 1000 // Definition of global constant, where maximum number of records to be evaluated is 1000.
FITNESS_DATA allData[MAX_RECORDS]; // Initialization of structured array of MAX_RECORDS size.
int currentLine = 0; // Variable initialized to keep track of which line is currently being evaluated.
char date[11]; // Standard character size of a date.
char time[6]; // Standard character size of time.
char steps[10]; // Steps unlikely to exceed 10 characters, so suitable maximum chosen.
char associatedDate[11]; // Variable to hold the date relating to a minimum or maximum step data.
char associatedTime[6]; // Variable to hold the time relating to a minimum or maximum step data.


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

        // Takes in the character the user types and stores in the choice variable.
        choice = getchar();
        // Gets rid of the newline character (obtained from course materials)
        while (getchar() != '\n');
        // Switch menu system with selectable cases.
        switch (choice)
        {
        // Two cases accounts for lower or upper case letter.
        case 'A':
        case 'a':
            // Prompts user for filename.
            printf("Input filename: ");

            // Reads in a line of max buffer size from the stdin user input.
            // Takes the string out of it and removes any spaces or newlines. (obtained from course materials)
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            // Opens the file for reading.
            FILE *input = fopen(filename, "r");

            // Sets the currentline tracking variable to 0.
            currentLine = 0;

            // If file does not open successfully, print an error and exit, otherwise execute the openFile function in the header file.
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            } else {
                openFile(input, allData, &lineCount);
            }
            break;


        case 'B':
        case 'b':
            // If file is open, print the total number of records using the lineCount variable calculated upon openFile function execution.
            // Otherwise, print an error and return back to menu prompt.
            if (input) {
                printf("Total records: %d\n", lineCount);
            }else{
                printf("Error: File not open\n");
            };
            break;


        case 'C':
        case 'c':
            // Execute minSteps function in the header file.
            minSteps(allData, lineCount, associatedDate, associatedTime);
            break;


        case 'D':
        case 'd':
            // Execute maxSteps function in the header file.
            maxSteps(allData, lineCount, associatedDate, associatedTime);
            break;


        case 'E':
        case 'e':
            // Execute meanSteps function in the header file.
            meanSteps(allData, lineCount);
            break;


        case 'F':
        case 'f':
            // Execute periodAbove500 function in the header file.
            periodAbove500(allData, lineCount);
            break;


        case 'Q':
        case 'q':
            return 0;
            break;


        // If user types anything that doesn't match the cases, print an error and return back to menu prompt.
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
        // Loops the menu system as long as the choice isn't the quit option. REFERENCE: https://www.quora.com/How-can-I-quit-the-program-in-switch-case-in-C-language answer by Eldo Frederick
        } while (choice != 'Q' && choice != 'q');

        return 0;
}









