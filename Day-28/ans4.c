//Write a program to Create contact management system.
#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[100];
    char phoneNumber[20];
    char email[100];
};

int main() {
    struct Contact contacts[100];
    int n = 0;

    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter contact ID: ");
                scanf("%d", &contacts[n].id);
                printf("Enter name: ");
                scanf("%s", contacts[n].name);
                printf("Enter phone number: ");
                scanf("%s", contacts[n].phoneNumber);
                printf("Enter email: ");
                scanf("%s", contacts[n].email);
                n++;
                break;
            case 2:
                printf("Contact Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d, Name: %s, Phone: %s, Email: %s\n", contacts[i].id, contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
                }
                break;
            case 3:
                int searchId;
                printf("Enter contact ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < n; i++) {
                    if(contacts[i].id == searchId) {
                        printf("Contact record found:\n");
                        printf("ID: %d, Name: %s, Phone: %s, Email: %s\n", contacts[i].id, contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
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