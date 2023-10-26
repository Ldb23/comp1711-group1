#include <stdio.h>
// Struct definition
struct student {
    char name [20];
    char student_id [11]; // Asuming up to 10 digits
    unsigned mark;
};

// Initialises
int main() {
    // Gives a name to access this student
    struct student new_student = {"Name Surname", "298932123", 35}; // Creates a record called new student
    printf("Student name: %s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Final Mark: %u\n", new_student.mark);
    return 0;
}