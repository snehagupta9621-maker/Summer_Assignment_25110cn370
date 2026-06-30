//Write a program to Create ATM simulation.
#include<stdio.h>
int main(){ 
    int pin, enteredPin, choice;
    float balance = 1000.0, amount;

    printf("Welcome to the ATM Simulation!\n");
    printf("Please enter your PIN: ");
    scanf("%d", &enteredPin);

    // Assuming the correct PIN is 1234
    pin = 1234;

    if(enteredPin != pin){
        printf("Incorrect PIN. Access denied.\n");
        return 0;
    }

    do {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: $");
                scanf("%f", &amount);
                if(amount > 0){
                    balance += amount;
                    printf("Deposit successful! New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid amount. Please try again.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: $");
                scanf("%f", &amount);
                if(amount > 0 && amount <= balance){
                    balance -= amount;
                    printf("Withdrawal successful! New balance: $%.2f\n", balance);
                } else {
                    printf("Invalid amount or insufficient funds. Please try again.\n");
                }
                break;
            case 4:
                printf("Thank you for using the ATM Simulation. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}