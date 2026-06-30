//Write a program to Write function to find factorial.
#include <stdio.h>
int factorial(int num) {
    if (num < 0) {
        return -1; // Factorial not defined for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int fact = factorial(num);
    if (fact == -1) {
        printf("Factorial is not defined for negative numbers.");
    } else {
        printf("Factorial of %d is %d.", num, fact);
    }
    return 0;
}