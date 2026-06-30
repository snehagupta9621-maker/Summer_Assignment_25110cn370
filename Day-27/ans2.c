//Write a program to Create employee management system. 
#include<stdio.h>
#include<string.h>

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

int main() {
    struct Employee employees[100];
    int n = 0;

    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &employees[n].id);
                printf("Enter employee name: ");
                scanf("%s", employees[n].name);
                printf("Enter employee age: ");
                scanf("%d", &employees[n].age);
                printf("Enter employee salary: ");
                scanf("%f", &employees[n].salary);
                n++;
                break;
            case 2:
                printf("Employee Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
                }
                break;
            case 3:
                int searchId;
                printf("Enter employee ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < n; i++) {
                    if(employees[i].id == searchId) {
                        printf("Employee found:\n");
                        printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
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