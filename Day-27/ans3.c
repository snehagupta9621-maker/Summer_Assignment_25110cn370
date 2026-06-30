//Write a program to Create salary management system.
#include<stdio.h>
#include<string.h>

struct Salary {
    int id;
    char name[50];
    float basicSalary;
    float allowance;
    float deduction;
};

int main() {
    struct Salary salaries[100];
    int n = 0;

    int choice;
    do {
        printf("\nSalary Management System\n");
        printf("1. Add Salary Record\n");
        printf("2. Display Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &salaries[n].id);
                printf("Enter employee name: ");
                scanf("%s", salaries[n].name);
                printf("Enter basic salary: ");
                scanf("%f", &salaries[n].basicSalary);
                printf("Enter allowance: ");
                scanf("%f", &salaries[n].allowance);
                printf("Enter deduction: ");
                scanf("%f", &salaries[n].deduction);
                n++;
                break;
            case 2:
                printf("Salary Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Basic Salary: %.2f, Allowance: %.2f, Deduction: %.2f\n", salaries[i].id, salaries[i].name, salaries[i].basicSalary, salaries[i].allowance, salaries[i].deduction);
                }
                break;
            case 3:
                int searchId;
                printf("Enter employee ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < n; i++) {
                    if(salaries[i].id == searchId) {
                        printf("Salary record found:\n");
                        printf("ID: %d, Name: %s, Basic Salary: %.2f, Allowance: %.2f, Deduction: %.2f\n", salaries[i].id, salaries[i].name, salaries[i].basicSalary, salaries[i].allowance, salaries[i].deduction);
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
