//Write a program to Develop complete mini project using arrays, strings and functions.
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_HISTORY 20

struct Transaction {
    char type[20];
    float amount;
    float balanceAfter;
    char timestamp[30];
};

struct Account {
    int accountNumber;
    char holderName[MAX_NAME_LENGTH];
    float balance;
    char accountType[20];
    int transactionCount;
    struct Transaction transactions[MAX_TRANSACTION_HISTORY];
};

// Utility functions
void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

char *getCurrentTime() {
    static char timestamp[30];
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    return timestamp;
}

int findAccountByNumber(struct Account accounts[], int count, int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void addTransactionRecord(struct Account *account, const char *type, float amount) {
    if (account->transactionCount < MAX_TRANSACTION_HISTORY) {
        strcpy(account->transactions[account->transactionCount].type, type);
        account->transactions[account->transactionCount].amount = amount;
        account->transactions[account->transactionCount].balanceAfter = account->balance;
        strcpy(account->transactions[account->transactionCount].timestamp, getCurrentTime());
        account->transactionCount++;
    }
}

// Core banking functions
void createAccount(struct Account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("\nBank system is full. Cannot create new account.\n");
        return;
    }

    struct Account newAccount;
    printf("\n--- Create New Account ---\n");
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    while (getchar() != '\n');

    if (findAccountByNumber(accounts, *count, newAccount.accountNumber) != -1) {
        printf("Account number already exists.\n");
        return;
    }

    printf("Enter account holder name: ");
    readLine(newAccount.holderName, sizeof(newAccount.holderName));

    printf("Enter initial balance: $");
    scanf("%f", &newAccount.balance);
    while (getchar() != '\n');

    printf("Enter account type (Savings/Checking/Business): ");
    readLine(newAccount.accountType, sizeof(newAccount.accountType));

    newAccount.transactionCount = 0;
    accounts[(*count)++] = newAccount;
    printf("Account created successfully!\n\n");
}

void displayAllAccounts(struct Account accounts[], int count) {
    if (count == 0) {
        printf("\nNo accounts in the bank.\n\n");
        return;
    }

    printf("\n===========================================\n");
    printf("           ALL BANK ACCOUNTS\n");
    printf("===========================================\n");
    printf("%-8s %-25s %-15s %-12s\n", "Acc No", "Holder Name", "Type", "Balance");
    printf("===========================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-25s %-15s $%.2f\n",
               accounts[i].accountNumber, accounts[i].holderName,
               accounts[i].accountType, accounts[i].balance);
    }
    printf("===========================================\n\n");
}

void searchAccount(struct Account accounts[], int count) {
    int accNumber;
    printf("\nEnter account number to search: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("\n=== Account Details ===\n");
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Holder Name: %s\n", accounts[index].holderName);
    printf("Account Type: %s\n", accounts[index].accountType);
    printf("Current Balance: $%.2f\n\n", accounts[index].balance);
}

void depositMoney(struct Account accounts[], int count) {
    int accNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    while (getchar() != '\n');

    if (amount <= 0) {
        printf("Invalid amount. Deposit must be positive.\n\n");
        return;
    }

    accounts[index].balance += amount;
    addTransactionRecord(&accounts[index], "Deposit", amount);
    printf("Deposit successful! New balance: $%.2f\n\n", accounts[index].balance);
}

void withdrawMoney(struct Account accounts[], int count) {
    int accNumber;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    while (getchar() != '\n');

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be positive.\n\n");
        return;
    }

    if (accounts[index].balance < amount) {
        printf("Insufficient balance. Current balance: $%.2f\n\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    addTransactionRecord(&accounts[index], "Withdrawal", amount);
    printf("Withdrawal successful! New balance: $%.2f\n\n", accounts[index].balance);
}

void transferMoney(struct Account accounts[], int count) {
    int fromAccNumber, toAccNumber;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &fromAccNumber);
    while (getchar() != '\n');

    int fromIndex = findAccountByNumber(accounts, count, fromAccNumber);
    if (fromIndex == -1) {
        printf("Sender account not found.\n\n");
        return;
    }

    printf("Enter recipient account number: ");
    scanf("%d", &toAccNumber);
    while (getchar() != '\n');

    int toIndex = findAccountByNumber(accounts, count, toAccNumber);
    if (toIndex == -1) {
        printf("Recipient account not found.\n\n");
        return;
    }

    printf("Enter amount to transfer: $");
    scanf("%f", &amount);
    while (getchar() != '\n');

    if (amount <= 0) {
        printf("Invalid amount. Transfer must be positive.\n\n");
        return;
    }

    if (accounts[fromIndex].balance < amount) {
        printf("Insufficient balance. Current balance: $%.2f\n\n", accounts[fromIndex].balance);
        return;
    }

    accounts[fromIndex].balance -= amount;
    accounts[toIndex].balance += amount;
    addTransactionRecord(&accounts[fromIndex], "Transfer Out", amount);
    addTransactionRecord(&accounts[toIndex], "Transfer In", amount);

    printf("Transfer successful!\n");
    printf("From: %s (New balance: $%.2f)\n", accounts[fromIndex].holderName, accounts[fromIndex].balance);
    printf("To: %s (New balance: $%.2f)\n\n", accounts[toIndex].holderName, accounts[toIndex].balance);
}

void checkBalance(struct Account accounts[], int count) {
    int accNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("\nAccount Holder: %s\n", accounts[index].holderName);
    printf("Current Balance: $%.2f\n\n", accounts[index].balance);
}

void showTransactionHistory(struct Account accounts[], int count) {
    int accNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    if (accounts[index].transactionCount == 0) {
        printf("\nNo transactions for this account.\n\n");
        return;
    }

    printf("\n=== Transaction History for %s ===\n", accounts[index].holderName);
    printf("%-15s %-12s %-12s %-20s\n", "Type", "Amount", "Balance", "Timestamp");
    printf("=================================================================\n");

    for (int i = 0; i < accounts[index].transactionCount; i++) {
        printf("%-15s $%-11.2f $%-11.2f %s\n",
               accounts[index].transactions[i].type,
               accounts[index].transactions[i].amount,
               accounts[index].transactions[i].balanceAfter,
               accounts[index].transactions[i].timestamp);
    }
    printf("=================================================================\n\n");
}

void updateAccountInfo(struct Account accounts[], int count) {
    int accNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("\nCurrent Details:\n");
    printf("Name: %s\n", accounts[index].holderName);
    printf("Account Type: %s\n\n", accounts[index].accountType);

    printf("Enter new name: ");
    readLine(accounts[index].holderName, sizeof(accounts[index].holderName));

    printf("Enter new account type: ");
    readLine(accounts[index].accountType, sizeof(accounts[index].accountType));

    printf("Account information updated successfully!\n\n");
}

void closeAccount(struct Account accounts[], int *count) {
    int accNumber;
    printf("\nEnter account number to close: ");
    scanf("%d", &accNumber);
    while (getchar() != '\n');

    int index = findAccountByNumber(accounts, *count, accNumber);
    if (index == -1) {
        printf("Account not found.\n\n");
        return;
    }

    printf("Account %d (%s) has been closed.\n", accounts[index].accountNumber, accounts[index].holderName);
    printf("Final balance: $%.2f\n\n", accounts[index].balance);

    for (int i = index; i < *count - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    (*count)--;
}

void calculateTotalDeposits(struct Account accounts[], int count) {
    if (count == 0) {
        printf("\nNo accounts in the bank.\n\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += accounts[i].balance;
    }

    printf("\n===================================\n");
    printf("Total deposits in bank: $%.2f\n", total);
    printf("Total accounts: %d\n", count);
    printf("Average balance: $%.2f\n", total / count);
    printf("===================================\n\n");
}

void displayMenu() {
    printf("\n=================================================\n");
    printf("      MINI BANK MANAGEMENT SYSTEM\n");
    printf("=================================================\n");
    printf("1.  Create a new account\n");
    printf("2.  Display all accounts\n");
    printf("3.  Search for an account\n");
    printf("4.  Deposit money\n");
    printf("5.  Withdraw money\n");
    printf("6.  Transfer money\n");
    printf("7.  Check balance\n");
    printf("8.  Show transaction history\n");
    printf("9.  Update account information\n");
    printf("10. Close an account\n");
    printf("11. Bank statistics\n");
    printf("12. Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
}

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    printf("========================================\n");
    printf("Welcome to Mini Bank Management System!\n");
    printf("========================================\n\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;

            case 2:
                displayAllAccounts(accounts, accountCount);
                break;

            case 3:
                searchAccount(accounts, accountCount);
                break;

            case 4:
                depositMoney(accounts, accountCount);
                break;

            case 5:
                withdrawMoney(accounts, accountCount);
                break;

            case 6:
                transferMoney(accounts, accountCount);
                break;

            case 7:
                checkBalance(accounts, accountCount);
                break;

            case 8:
                showTransactionHistory(accounts, accountCount);
                break;

            case 9:
                updateAccountInfo(accounts, accountCount);
                break;

            case 10:
                closeAccount(accounts, &accountCount);
                break;

            case 11:
                calculateTotalDeposits(accounts, accountCount);
                break;

            case 12:
                printf("Thank you for using Mini Bank Management System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}