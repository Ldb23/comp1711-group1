#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

char date[11]; // Initialises an empty character array
char time[6]; // Initialises an empty character array
char steps[10];  // Initialises a large enough char array to hold a typical step count as a string
int totalLines = 0; // Initialises a line count variable

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

// Complete the main function
int main() {

    // Calls a function to read the fitness data
    FILE *file = open_file("FitnessData_2023.csv", "r");

    // Size of container for the line you are reading
    int buffer_size = 100;
    
    // Stores line into containers of buffer size
    char line_buffer[buffer_size];

    FITNESS_DATA allData[59];

    // While lines have some text, print each line
    while (fgets(line_buffer, buffer_size, file) != NULL) {

        // Counts the number of lines in the csv file, and thus the required array size
        totalLines += 1;
        
        // Splits the input (current line being read) by the , to output assignments to date, time and steps variables
        tokeniseRecord(line_buffer, ",", date, time, steps);

        
        strcpy(allData[totalLines - 1].date, date); // Assigns the date in the current line, to the date in the allData struct at the current element
        strcpy(allData[totalLines - 1].time, time); // Assigns the time in the current line, to the time in the allData struct at the current element
        allData[totalLines - 1].steps = atoi(steps); // Assigns the converted integer equiv of steps in the current line, to the steps in the allData struct at the current element

    }
    
    fclose(file);

    // Prints the total number of records in file, in the specified format
    printf("Number of records in file: %d\n", totalLines);

    // Prints the first three lines of the file in the specified format of date/time/steps
    for (int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", allData[i].date, allData[i].time, allData[i].steps);
    }
    

}
