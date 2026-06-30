//Write a program to Create mini employee management system.
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 50

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    float salary;
};

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int findEmployeeById(struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee record system is full.\n");
        return;
    }

    struct Employee newEmployee;
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    while (getchar() != '\n');

    if (findEmployeeById(employees, *count, newEmployee.id) != -1) {
        printf("Employee ID already exists.\n");
        return;
    }

    printf("Enter employee name: ");
    readLine(newEmployee.name, sizeof(newEmployee.name));

    printf("Enter employee department: ");
    readLine(newEmployee.department, sizeof(newEmployee.department));

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    while (getchar() != '\n');

    employees[(*count)++] = newEmployee;
    printf("Employee added successfully.\n\n");
}

void displayEmployees(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the record system.\n\n");
        return;
    }

    printf("\n=== Employee Records ===\n");
    printf("%-5s %-25s %-30s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("====================================================================================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s %-30s $%.2f\n",
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
    printf("====================================================================================================\n\n");
}

void searchEmployee(struct Employee employees[], int count) {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee not found.\n\n");
        return;
    }

    printf("\n=== Employee Found ===\n");
    printf("ID: %d\n", employees[index].id);
    printf("Name: %s\n", employees[index].name);
    printf("Department: %s\n", employees[index].department);
    printf("Salary: $%.2f\n\n", employees[index].salary);
}

void updateEmployee(struct Employee employees[], int count) {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee not found.\n\n");
        return;
    }

    printf("\nCurrent Details:\n");
    printf("Name: %s\n", employees[index].name);
    printf("Department: %s\n", employees[index].department);
    printf("Salary: $%.2f\n\n", employees[index].salary);

    printf("Enter new name: ");
    readLine(employees[index].name, sizeof(employees[index].name));

    printf("Enter new department: ");
    readLine(employees[index].department, sizeof(employees[index].department));

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    while (getchar() != '\n');

    printf("Employee updated successfully.\n\n");
}

void deleteEmployee(struct Employee employees[], int *count) {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findEmployeeById(employees, *count, id);
    if (index == -1) {
        printf("Employee not found.\n\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    (*count)--;
    printf("Employee deleted successfully.\n\n");
}

void calculateTotalSalary(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the system.\n\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += employees[i].salary;
    }

    printf("\nTotal Salary of All Employees: $%.2f\n\n", total);
}

void calculateAverageSalary(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the system.\n\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += employees[i].salary;
    }

    float average = total / count;
    printf("\nAverage Salary: $%.2f\n\n", average);
}

void findHighestSalary(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the system.\n\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (employees[i].salary > employees[maxIndex].salary) {
            maxIndex = i;
        }
    }

    printf("\n=== Highest Paid Employee ===\n");
    printf("ID: %d\n", employees[maxIndex].id);
    printf("Name: %s\n", employees[maxIndex].name);
    printf("Department: %s\n", employees[maxIndex].department);
    printf("Salary: $%.2f\n\n", employees[maxIndex].salary);
}

void displayByDepartment(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees in the system.\n\n");
        return;
    }

    char dept[MAX_DEPARTMENT_LENGTH];
    printf("Enter department name: ");
    readLine(dept, sizeof(dept));

    printf("\n=== Employees in %s Department ===\n", dept);
    printf("%-5s %-25s %-10s\n", "ID", "Name", "Salary");
    printf("===================================================\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].department, dept) == 0) {
            printf("%-5d %-25s $%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
        }
    }

    if (!found) {
        printf("No employees found in this department.\n");
    }
    printf("===================================================\n\n");
}

void displayMenu() {
    printf("\n=================================================\n");
    printf("   EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("=================================================\n");
    printf("1. Add an employee\n");
    printf("2. Display all employees\n");
    printf("3. Search for an employee\n");
    printf("4. Update employee details\n");
    printf("5. Delete an employee\n");
    printf("6. Display employees by department\n");
    printf("7. Calculate total salary\n");
    printf("8. Calculate average salary\n");
    printf("9. Find highest paid employee\n");
    printf("10. Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    printf("Welcome to Employee Management System!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\n--- Add Employee ---\n");
                addEmployee(employees, &employeeCount);
                break;

            case 2:
                displayEmployees(employees, employeeCount);
                break;

            case 3:
                printf("\n--- Search Employee ---\n");
                searchEmployee(employees, employeeCount);
                break;

            case 4:
                printf("\n--- Update Employee ---\n");
                updateEmployee(employees, employeeCount);
                break;

            case 5:
                printf("\n--- Delete Employee ---\n");
                deleteEmployee(employees, &employeeCount);
                break;

            case 6:
                printf("\n--- Filter by Department ---\n");
                displayByDepartment(employees, employeeCount);
                break;

            case 7:
                calculateTotalSalary(employees, employeeCount);
                break;

            case 8:
                calculateAverageSalary(employees, employeeCount);
                break;

            case 9:
                findHighestSalary(employees, employeeCount);
                break;

            case 10:
                printf("Thank you for using Employee Management System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}