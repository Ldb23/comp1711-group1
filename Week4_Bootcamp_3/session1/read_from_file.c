#include <stdio.h>

int main() {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100; // aka size of container for the line that you're reading, in this case, if 100 chars its ok
    char line_buffer[buffer_size];
    // Reads file line by line into a buffer
    // If buffer is too small, only the beginning of the line will be read
    // Buffer should be larger than longest line plus one extra character
    // Inputs: Where we're storing buffer, size of the buffer, file we're reading from
    while (fgets(line_buffer, buffer_size, file) != NULL) { 
        printf("%s", line_buffer); // Prints contents of line buffer on every iteration
    }

    fclose(file);
    return 0;
}