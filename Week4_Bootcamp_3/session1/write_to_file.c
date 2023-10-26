#include <stdio.h>

int main() {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w"); // For task 1, don't use w, use r for reading instead
    if (file == NULL) {
        perror("");
        return 1;
    }

    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number); // Write to file with fprintf (basically printf but for files)
    }

    fclose(file);
    return 0;
}