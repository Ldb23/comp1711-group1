
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#define buffer_size 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Definition of appropriate struct.
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function provided in template. Splits up the line into useful data.
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

// Function which executes when file is specified to open. Stores all the data in a structured array for later use whilst also counting the number of entries.
void openFile(FILE *input, FITNESS_DATA allData[], int *lineCount) {
	char line[buffer_size];
	int currentLine = 0;
	char date[11];
	char time[6];
	char steps[10];
	// Loop whilst there is some contents of the current line.
	while (fgets(line, buffer_size, input) != NULL) {
		// Increment the currentLine variable to keep track of which line is being evaluated, similar to i in for loops.
		currentLine += 1;
		// Increment the lineCount using a pointer to globally change the variable so other functions can access. REFERENCE: https://stackoverflow.com/questions/29423757/why-use-pointers-in-c answer by tuckermi.
		*lineCount += 1;
		// Split up the line into date, time and steps data using the , as a delimitter.
		tokeniseRecord(line, ",", date, time, steps);
		// Copy the date string into the current indexed allData.date.
		strcpy(allData[currentLine - 1].date, date); 
		// Copy the time string into the current indexed allData.time.
		strcpy(allData[currentLine - 1].time, time);
		// Convert the steps string into an integer and store into the current indexed allData.steps.
		allData[currentLine - 1].steps = atoi(steps);
	}
	// Print success message as required.
	printf("File successfully loaded.\n");
}

// Function to calculate smallest number of steps, and it's associated date/time.
void minSteps(FITNESS_DATA allData[], int lineCount, char associatedDate[], char associatedTime[]) {
	// Initializes an unrealistic minSteps variable value for comparison.
	int minSteps = 20000;
	// Loops through each index of the structured array allData and compares the step data to the minSteps variable.
	for (int i = 0; i < lineCount; i++){
		// If steps are lower than minSteps, assign this value to minSteps.
		if (allData[i].steps < minSteps) {
			minSteps = allData[i].steps;
			// Copy the current date and time to the associatedDate and associatedTime variables for reference.
			strcpy(associatedDate, allData[i].date);
			strcpy(associatedTime, allData[i].time);
		}
	}
	// Print the date and time where the minSteps occurs.
	printf("Fewest steps: %s %s\n", associatedDate, associatedTime);
}

// Function to calculate the largest number of steps, and it's associated date/time.
void maxSteps(FITNESS_DATA allData[], int lineCount, char associatedDate[], char associatedTime[]) {
	// Initializes a maxSteps variable with the lowest possible steps for comparison.
	int maxSteps = 0;
	// Loops through each index of the structured array allData and compares the step data to the maxSteps variable.
	for (int i = 0; i < lineCount; i++){
		// If steps are greater than maxSteps, assign this value to maxSteps.
		if (allData[i].steps > maxSteps) {
			maxSteps = allData[i].steps;
			// Copy the current date and time to the associatedDate and associatedTime variables for reference.
			strcpy(associatedDate, allData[i].date);
			strcpy(associatedTime, allData[i].time);
		}
	}
	// Print the date and time where the maxSteps occurs.
	printf("Largest steps: %s %s\n", associatedDate, associatedTime);
}

// Function to calculate mean number of steps, by summing all steps and dividing by the number of entries.
void meanSteps(FITNESS_DATA allData[], int lineCount){
	// Initializes two variables to store keep track of the total number of steps, and the final mean number of steps.
	int totalSteps = 0;
	int meanSteps = 0;
	// Looping through the allData array and adding the steps to the running total upon each iteration.
	for (int i = 0; i < lineCount; i++){
		totalSteps += allData[i].steps;}
	// Mean number of steps calculated from total steps divided by the number of entries, i.e. lines.
	// Math library imported to round due to truncation errors upon first submission. Numerator converted to float to output a decimal mean to then be rounded.
	// Ideas from the following REFERENCE: https://cboard.cprogramming.com/cplusplus-programming/102114-int-division-float.html answer by Yarin
	meanSteps = round((float)totalSteps / lineCount);
	// Print output as required.
	printf("Mean step count: %d\n", (int)meanSteps);
}

// Function to find the longest period where steps are above 500. 
void periodAbove500(FITNESS_DATA allData[], int lineCount){

	int periodLength = 0; // Initializes a variable to track the current number of sequential data points where steps are over 500, i.e. time period.
	int periodStart = -1; // Intializes a variable for the line number of the starting period, -1 selected as 0th index may contain the start date/time for the longest period.
	int longestPeriodLength = 0; // Initializes a variable to contain the longest period length, i.e. number of sequential entries.
	int longestPeriodStart = 0; // Initializes a variable to store the current longest period length.

	// Loops through the allData structured array.
	for (int i = 0; i < lineCount; i++){
		// If the steps at the current index are greater than 500, evaluate if the start period is already in the periodStart variable.
		if (allData[i].steps > 500) {
			// If periodStart is at the default impossible value, set the periodStart to the current index.
			if (periodStart == -1) { // Equivalence operator over assignment operator to check rather than change. REFERENCE: https://www.quora.com/What-is-the-different-between-in-C answer by Monisha Ch
				periodStart = i;}
			// Then increment the periodLength to keep track of number of sequential entries that have steps greater than 500.
			periodLength += 1;
			// If current period length is greater than the longest period length, assign the current to the longest and assign the start index reference to the longest start variable.
			if (periodLength > longestPeriodLength) {
				longestPeriodLength = periodLength;
				longestPeriodStart = periodStart;
				}
		// When the steps are lower than 500, reset the periodStart and periodLength variables to their default values.
		} else {
			periodStart = -1; 
			periodLength = 0;
		}
	}
	// Print the period start using the longest variables to index the allData for the correct start date/time.
	printf("Longest period start: %s %s\n", allData[longestPeriodStart].date, allData[longestPeriodStart].time);
	// Print the period end using the longest variables to index the allData for the correct end date/time. Start can be summed with length -1 to obtain the data at the ending entry of the range, as arrays start index at 0.
	printf("Longest period end: %s %s\n", allData[longestPeriodStart + longestPeriodLength - 1].date, allData[longestPeriodStart + longestPeriodLength - 1].time);
}

#endif // FITNESS_DATA_STRUCT_H
