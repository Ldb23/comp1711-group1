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

    int totalLines = 0;
    // Size of container for the line you are reading
    int buffer_size = 100;
    // Stores line into containers of buffer size
    char line_buffer[buffer_size];

    // While lines have some text, print each line
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        // Counts the number of lines in the csv file, and thus the required array size
        totalLines += 1;
    }

    printf("Number of records in file: %d\n", totalLines);

    fclose(file);

    // Defines an array of 3 length, of the struct type (needs to define array of size: total csv)
    FITNESS_DATA allData[3];

    // need three arrays of split data which can then be put into allData as needed
    char *date[] = {"DATE1", "DATE2", "DATE3"};
    char *time[] = {"time1", "time2", "time3"};
    unsigned steps[] = {1, 2, 3};

    // Loops through all the above variables, and appends the empty allData array with the corresponding elements from the above
    for (int i = 0; i < 3; i++) {
        strcpy(allData[i].date, date[i]);
        strcpy(allData[i].time, time[i]);
        allData[i].steps = steps[i];
    }

    // Prints the first three lines of allData as required
    printf("First Three Lines\n");
    for (int i = 0; i < 3; i++) {
        printf("%s/%s/%d\n", allData[i].date, allData[i].time, allData[i].steps);
    }

}
