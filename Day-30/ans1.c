//Write a program to Create student record system using arrays and strings.
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
};

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int findStudentById(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student record system is full.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    while (getchar() != '\n');

    if (findStudentById(students, *count, newStudent.id) != -1) {
        printf("Student ID already exists.\n");
        return;
    }

    printf("Enter student name: ");
    readLine(newStudent.name, sizeof(newStudent.name));

    printf("Enter student grade: ");
    scanf("%f", &newStudent.grade);
    while (getchar() != '\n');

    students[(*count)++] = newStudent;
    printf("Student added successfully.\n\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students in the record system.\n\n");
        return;
    }

    printf("\n=== Student Records ===\n");
    printf("%-5s %-25s %-10s\n", "ID", "Name", "Grade");
    printf("==============================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s %.2f\n",
               students[i].id, students[i].name, students[i].grade);
    }
    printf("==============================================\n\n");
}

void searchStudent(struct Student students[], int count) {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student not found.\n\n");
        return;
    }

    printf("\n=== Student Found ===\n");
    printf("ID: %d\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("Grade: %.2f\n\n", students[index].grade);
}

void updateStudent(struct Student students[], int count) {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student not found.\n\n");
        return;
    }

    printf("\nCurrent Details:\n");
    printf("Name: %s\n", students[index].name);
    printf("Grade: %.2f\n\n", students[index].grade);

    printf("Enter new name: ");
    readLine(students[index].name, sizeof(students[index].name));

    printf("Enter new grade: ");
    scanf("%f", &students[index].grade);
    while (getchar() != '\n');

    printf("Student updated successfully.\n\n");
}

void deleteStudent(struct Student students[], int *count) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findStudentById(students, *count, id);
    if (index == -1) {
        printf("Student not found.\n\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("Student deleted successfully.\n\n");
}

void calculateAverageGrade(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to calculate average grade.\n\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].grade;
    }

    float average = total / count;
    printf("\nAverage Grade: %.2f\n\n", average);
}

void findTopStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students in the record system.\n\n");
        return;
    }

    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].grade > students[topIndex].grade) {
            topIndex = i;
        }
    }

    printf("\n=== Top Student ===\n");
    printf("ID: %d\n", students[topIndex].id);
    printf("Name: %s\n", students[topIndex].name);
    printf("Grade: %.2f\n\n", students[topIndex].grade);
}

void displayMenu() {
    printf("\n================================================\n");
    printf("    STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("================================================\n");
    printf("1. Add a student\n");
    printf("2. Display all students\n");
    printf("3. Search for a student\n");
    printf("4. Update student details\n");
    printf("5. Delete a student\n");
    printf("6. Calculate average grade\n");
    printf("7. Find top student\n");
    printf("8. Exit\n");
    printf("================================================\n");
    printf("Enter your choice: ");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    printf("Welcome to Student Record Management System!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\n--- Add Student ---\n");
                addStudent(students, &studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                printf("\n--- Search Student ---\n");
                searchStudent(students, studentCount);
                break;

            case 4:
                printf("\n--- Update Student ---\n");
                updateStudent(students, studentCount);
                break;

            case 5:
                printf("\n--- Delete Student ---\n");
                deleteStudent(students, &studentCount);
                break;

            case 6:
                calculateAverageGrade(students, studentCount);
                break;

            case 7:
                findTopStudent(students, studentCount);
                break;

            case 8:
                printf("Thank you for using Student Record Management System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}