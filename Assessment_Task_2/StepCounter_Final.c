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
#define MAX_RECORDS 1000
FITNESS_DATA allData[MAX_RECORDS];
int currentLine = 0;
char date[11];
char time[6];
char steps[10];
char associatedDate[11];
char associatedTime[6];
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

        choice = getchar();

        while (getchar() != '\n');

        switch (choice)
        {

        case 'A':
        case 'a':
            printf("Input filename: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            currentLine = 0;
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;
            } else {
                while (fgets(line, buffer_size, input) != NULL) {

                    // Keeps track of current line being read in the while loop
                    currentLine += 1;
                    lineCount += 1;
                    tokeniseRecord(line, ",", date, time, steps);
                    strcpy(allData[currentLine - 1].date, date); 
                    strcpy(allData[currentLine - 1].time, time); 
                    allData[currentLine - 1].steps = atoi(steps);
                }
                printf("File successfully loaded.\n");
            }
            break;


        case 'B':
        case 'b':
            if (input) {
                printf("Total records: %d\n", lineCount);
            }else{
                printf("Error: File not open\n");
            };
            break;


        case 'C':
        case 'c':
            {int minSteps = 20000;
            for (int i = 0; i < lineCount; i++){
                if (allData[i].steps < minSteps) {
                    minSteps = allData[i].steps;
                    strcpy(associatedDate, allData[i].date);
                    strcpy(associatedTime, allData[i].time);
                }
            }
            printf("Fewest steps: %s %s\n", associatedDate, associatedTime);
            }
            break;


        case 'D':
        case 'd':
            {int maxSteps = 0;
            for (int i = 0; i < lineCount; i++){
                if (allData[i].steps > maxSteps) {
                    maxSteps = allData[i].steps;
                    strcpy(associatedDate, allData[i].date);
                    strcpy(associatedTime, allData[i].time);
                }
            }
            printf("Largest steps: %s %s\n", associatedDate, associatedTime);
            }
            break;


        case 'E':
        case 'e':
            {int totalSteps = 0;
            int meanSteps = 0;
            for (int i = 0; i < lineCount; i++){
                totalSteps += allData[i].steps;}
            meanSteps = totalSteps / lineCount;
            printf("Mean step count: %d\n", meanSteps);
            }
            break;


        case 'F':
        case 'f':
            {
                int periodLength = 0;
                int periodStart = -1;
                int longestPeriodLength = 0;
                int longestPeriodStart = 0;

                for (int i = 0; i < lineCount; i++){
                    if (allData[i].steps > 500) {
                        if (periodStart == -1) {
                            periodStart = i;}
                        periodLength += 1;
                        if (periodLength > longestPeriodLength) {
                            longestPeriodLength = periodLength;
                            longestPeriodStart = periodStart;
                            }
                    } else {
                        periodStart = -1; 
                        periodLength = 0;
                    }
                }
                printf("Longest period start: %s %s\n", allData[longestPeriodStart].date, allData[longestPeriodStart].time);
                printf("Longest period end: %s %s\n", allData[longestPeriodStart + longestPeriodLength - 1].date, allData[longestPeriodStart + longestPeriodLength - 1].time);
            }
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









