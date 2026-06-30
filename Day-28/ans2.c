//Write a program to Create bank account system.
#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char accountHolderName[100];
    float balance;
};

int main() {
    struct BankAccount accounts[100];
    int n = 0;

    int choice;
    do {
        printf("\nBank Account System\n");
        printf("1. Create Account\n");
        printf("2. Display Account Details\n");
        printf("3. Search Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accounts[n].accountNumber);
                printf("Enter account holder name: ");
                scanf("%s", accounts[n].accountHolderName);
                printf("Enter initial balance: ");
                scanf("%f", &accounts[n].balance);
                n++;
                break;
            case 2:
                printf("Account Details:\n");
                for(int i = 0; i < n; i++) {
                    printf("Account Number: %d, Holder Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].accountHolderName, accounts[i].balance);
                }
                break;
            case 3:
                int searchAccountNumber;
                printf("Enter account number to search: ");
                scanf("%d", &searchAccountNumber);
                for(int i = 0; i < n; i++) {
                    if(accounts[i].accountNumber == searchAccountNumber) {
                        printf("Account record found:\n");
                        printf("Account Number: %d, Holder Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].accountHolderName, accounts[i].balance);
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