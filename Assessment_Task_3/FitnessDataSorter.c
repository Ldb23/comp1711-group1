#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data.
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

#define buffer_size 100
char line[buffer_size]; // To define the max size of a given line in the file to be opened.
char filename[buffer_size]; // To define the max size of the file name to be opened.
int lineCount = 0; // Variable initialized to count the number of lines in a file.
int currentLine = 0; // Variable to keep track of currentLine being read.
#define MAX_RECORDS 1000 // Definition of global constant, where maximum number of records to be evaluated is 1000.
FitnessData allData[MAX_RECORDS]; // Initialization of structured array of MAX_RECORDS size.
char date[11];
char time[6];
char steps[10];

// Function to tokenize a record
void tokeniseRecord(char *record, char *delimiter, char *date, char *time, char *steps) {
    char *ptr = strtok(record, delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, delimiter);
            if (ptr != NULL) {
                strcpy(steps, ptr);
            }
        }
    }
}


int main() {
    // Menu to prompt for a filename.
    printf("Enter filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    // Opens filename.
    FILE *input = fopen(filename, "r");
    currentLine = 0;
    // Checks if file exists.
    if (!input)
    {
        // Prints error if not.
        printf("Error: invalid file\n");
        return 1;
    } else {
        // Loop to split data by commas and assign to the allData array of structs.
        while (fgets(line, buffer_size, input) != NULL) {

            // Keeps track of current line being read in the while loop
            currentLine += 1;
            lineCount += 1;
            tokeniseRecord(line, ",", date, time, steps);
            // Checks if any part of the data is not in the right format or missing.
            if (strlen(date) != 10 || strlen(time) != 5 || strlen(steps) < 2 || date[0] == '\0' || time[0] == '\0' || steps[0] == '\0') {
                // Prints error if any data entries are missing.
                printf("Error: invalid file\n");
                fclose(input);
                return 1;
            } else {
                strcpy(allData[currentLine - 1].date, date); 
                strcpy(allData[currentLine - 1].time, time); 
                allData[currentLine - 1].steps = atoi(steps);
            }
        }
    }
    fclose(input);

    // Write a file with the same file name + .tsv.
    char newFilename[100];
    strcpy(newFilename, filename); // Duplicate filename to newFilename.
    strcat(newFilename, ".tsv"); // Cat .tsv onto newFilename.
    FILE *file = fopen(newFilename, "w"); // Creates a FILE pointer, w indicates to write to.
    if (file == NULL) { // If file is errored...
        printf("Error: invalid file\n"); // Prints the last error.
        return 1; // Returns an error message (unlike success message with return 0).
    } else {
        // Bubble sort to sort array of structs into ascending order by steps.
        // Modified for an array of structs from procedure at the following reference:
        // https://www.youtube.com/watch?v=qLVrwCvVPGo&t=206
        for(int i = 0; i < lineCount - 1; i++) {
            for(int j = 0; j < lineCount - 1; j++) {
                if(allData[j].steps < allData[j+1].steps) {
                    char dateTemp[11];
                    char timeTemp[6];
                    int stepsTemp;
                    strcpy(dateTemp, allData[j].date);
                    strcpy(timeTemp, allData[j].time);
                    stepsTemp = allData[j].steps;

                    strcpy(allData[j].date, allData[j+1].date);
                    strcpy(allData[j].time, allData[j+1].time);
                    allData[j].steps = allData[j+1].steps;

                    strcpy(allData[j+1].date, dateTemp);
                    strcpy(allData[j+1].time, timeTemp);
                    allData[j+1].steps = stepsTemp;
                }
            }
        }
        // Prints data from array of structs into tab seperated lines.
        for (int k = 0; k < lineCount; k++) {
            fprintf(file, "%s\t%s\t%d\n", allData[k].date, allData[k].time, allData[k].steps);
        }
        printf("Data sorted and written to %s\n", newFilename);
    }
    fclose(file);
    return 0;
}
