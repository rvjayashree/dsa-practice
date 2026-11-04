/*
 * Experiment: Student Records Management using Dynamic Memory Allocation
 * Subject: Data Structures and Algorithms Laboratory
 * 
 * Description:
 * Demonstrates heap memory allocation using malloc(), realloc(), and free()
 * to store, display, and dynamically expand an array of student record structures.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition for Student */
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

/* Function to read details of students */
void readStudents(struct Student *students, int startIndex, int count) {
    for (int i = startIndex; i < startIndex + count; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &(students[i].rollNo));
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }
}

/* Function to display all student records */
void displayStudents(struct Student *students, int total) {
    if (total == 0) {
        printf("\nNo student records to display.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-10d %-30s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
    printf("------------------------------------------------------------\n");
}

int main() {
    struct Student *students = NULL;
    int currentCount = 0;
    int initialCount = 0;
    int extraCount = 0;

    printf("Enter initial number of student records to create: ");
    if (scanf("%d", &initialCount) != 1 || initialCount <= 0) {
        printf("Invalid record count.\n");
        return 1;
    }

    /* Allocate memory on the heap using malloc() */
    students = (struct Student *)malloc(initialCount * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    readStudents(students, 0, initialCount);
    currentCount = initialCount;

    printf("\n--- Displaying Initial Records ---");
    displayStudents(students, currentCount);

    /* Expand memory dynamically using realloc() */
    printf("\nEnter number of additional student records to append: ");
    if (scanf("%d", &extraCount) == 1 && extraCount > 0) {
        struct Student *temp = (struct Student *)realloc(students, (currentCount + extraCount) * sizeof(struct Student));
        if (temp == NULL) {
            printf("Memory reallocation failed! Preserving existing records.\n");
        } else {
            students = temp;
            readStudents(students, currentCount, extraCount);
            currentCount += extraCount;

            printf("\n--- Displaying Updated Records After realloc() ---");
            displayStudents(students, currentCount);
        }
    }

    /* Release dynamically allocated heap memory */
    free(students);
    students = NULL;
    printf("\nHeap memory successfully released.\n");

    return 0;
}
