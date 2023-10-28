#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

char date[11]; // Initialises an empty character array
char time[6]; // Initialises an empty character array
char steps[10];  // Initialises a large enough char array to hold a typical step count as a string
int buffer_size = 100; // Initialises a buffer size for lines in the csv file (100 more than sufficient for standard date,time,steps format)
int lineCount = 0; // Initialises a line count variable
int currentLine = 0; // Initialises a line tracking variable

// Function defined to open file
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}

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

// Main function
int main() {

    // Calls a function to read the fitness data. (To be able to count the number of lines)
    FILE *file1 = open_file("FitnessData_2023.csv", "r");

    // Stores line into containers of buffer size
    char line_buffer[buffer_size];

    // While lines have some text, increment the lineCount
    while (fgets(line_buffer, buffer_size, file1) != NULL) {
        lineCount += 1;
    }
    fclose(file1);

    // Now an array of structs is defined with size = the number of lines of fitness data
    FITNESS_DATA allData[lineCount];

    // Calls a function to read the fitness data. (To be able to populate allData)
    FILE *file2 = open_file("FitnessData_2023.csv", "r");

    while (fgets(line_buffer, buffer_size, file2) != NULL) {

        // Keeps track of current line being read in the while loop
        currentLine += 1;
        
        // Splits the input (current line being read) by the , to output assignments to the globally defined date, time and steps variables
        tokeniseRecord(line_buffer, ",", date, time, steps);

        strcpy(allData[currentLine - 1].date, date); // Assigns the date in the current line, to the date in the allData struct at the current element
        strcpy(allData[currentLine - 1].time, time); // Assigns the time in the current line, to the time in the allData struct at the current element
        allData[currentLine - 1].steps = atoi(steps); // Assigns the converted integer equiv of steps in the current line, to the steps in the allData struct at the current element

    }
    
    fclose(file2);

    // Prints the total number of records in file, in the specified format
    printf("Number of records in file: %d\n", lineCount);

    // Prints the first three lines of the file in the specified format of date/time/steps
    for (int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", allData[i].date, allData[i].time, allData[i].steps);
    }

    return 0;
}
