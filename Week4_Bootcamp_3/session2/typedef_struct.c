#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11];
    unsigned mark;
} STUDENT;

int main () {
    int number_of_students = 10, i;
    STUDENT students [] = {...}; // Initialisation goes here
    for (i = 0; i < number_of_students; i++) {
        printf("-----------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %s\n", students[i].mark);
    }
    printf("----------------\n");
    return 0;
}