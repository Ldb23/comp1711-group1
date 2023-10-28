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

char date[11]; // Empty character array
char time[6]; // Empty character array
char steps[10];  // Large enough to hold a typical step count as a string

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}
// Read in CSV File
// Store it in the correct size array
// Use typedef data structure
// Write the number of records in the file to the screen
// Write to the screen the first three rows of the file


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
    // Initialises a line count variable
    int totalLines = 0;
    // Size of container for the line you are reading
    int buffer_size = 100;
    // Stores line into containers of buffer size
    char line_buffer[buffer_size];

    FITNESS_DATA allData[59];

    // While lines have some text, print each line
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        // Counts the number of lines in the csv file, and thus the required array size
        totalLines += 1;
        char date[11]; // Empty character array
        char time[6]; // Empty character array
        char steps[10];  // Large enough to hold a typical step count as a string
        
        // record input identifies which string in the array, and the "," is (where it should be split) the delimiter
        // Outputs useful date time and steps data
        tokeniseRecord(line_buffer, ",", date, time, steps);
        strcpy(allData[totalLines - 1].date, date);
        strcpy(allData[totalLines - 1].time, time);
        allData[totalLines - 1].steps = atoi(steps);

    }
    
    fclose(file);

    printf("Number of records in file: %d\n", totalLines);

    for (int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", allData[i].date, allData[i].time, allData[i].steps);
    }
    

}
