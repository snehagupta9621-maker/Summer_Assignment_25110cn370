//Write a program to Print Armstrong numbers 
#include <stdio.h>

int main() {
    int low, high, num, originalNum, remainder, result;

    printf("Enter the lower interval: ");
    scanf("%d", &low);
    printf("Enter the higher interval: ");
    scanf("%d", &high);

    printf("Armstrong numbers between %d and %d are: ", low, high);

    for (num = low; num <= high; ++num) {
        originalNum = num;
        result = 0;

        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += remainder * remainder * remainder;
            originalNum /= 10;
        }

        if (result == num) {
            printf("%d ", num);
        }
    }

    return 0;
}