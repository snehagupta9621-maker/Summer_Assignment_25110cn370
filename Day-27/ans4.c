//Write a program to Create marksheet generation system. 
#include<stdio.h>
#include<string.h>

struct Student {
    int id;
    char name[50];
    float marks[5]; // Assuming 5 subjects
};

int main() {
    struct Student students[100];
    int n = 0;

    int choice;
    do {
        printf("\nMarksheet Generation System\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &students[n].id);
                printf("Enter student name: ");
                scanf("%s", students[n].name);
                printf("Enter marks for 5 subjects:\n");
                for(int i = 0; i < 5; i++) {
                    printf("Subject %d: ", i + 1);
                    scanf("%f", &students[n].marks[i]);
                }
                n++;
                break;
            case 2:
                printf("Student Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Marks: ", students[i].id, students[i].name);
                    for(int j = 0; j < 5; j++) {
                        printf("%.2f ", students[i].marks[j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                int searchId;
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < n; i++) {
                    if(students[i].id == searchId) {
                        printf("Student record found:\n");
                        printf("ID: %d, Name: %s, Marks: ", students[i].id, students[i].name);
                        for(int j = 0; j < 5; j++) {
                            printf("%.2f ", students[i].marks[j]);
                        }
                        printf("\n");
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