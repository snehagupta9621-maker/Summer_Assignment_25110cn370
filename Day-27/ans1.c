//Write a program to Create student record management system. 

#include<stdio.h>
#include<string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[100];
    int n = 0;

    int choice;
    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &students[n].id);
                printf("Enter student name: ");
                scanf("%s", students[n].name);
                printf("Enter student age: ");
                scanf("%d", &students[n].age);
                printf("Enter student GPA: ");
                scanf("%f", &students[n].gpa);
                n++;
                break;
            case 2:
                printf("Student Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
                }
                break;
            case 3:
                int searchId;
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < n; i++) {
                    if(students[i].id == searchId) {
                        printf("Student found:\n");
                        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
                        break;
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}