while (fgets(line_buffer, buffer_size, file) != NULL) { 
        printf("%d\n", atoi(line_buffer)); // Prints contents of line buffer on every iteration
    }

    atoi changes to integer which is relevant for step data in task 1