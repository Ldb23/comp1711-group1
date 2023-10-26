#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}

// Instead we have now obtained the read file by calling a function instead
int main() {
    FILE *file = open_file("data.txt", "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) { 
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}
