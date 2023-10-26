#include <stdio.h>

int main() {
    char filename [] = "data.txt"; // Create a file called data.txt
    FILE *file = fopen(filename, "w"); // Creates a FILE pointer, w indicates to write to
    if (file == NULL) { // If file is errored
        perror(""); // Prints the last error
        return 1; // Returns an error message (unlike success message with return 0)
    }

    fclose(file); // *critical* Close the file after you're done
    return 0;
}   