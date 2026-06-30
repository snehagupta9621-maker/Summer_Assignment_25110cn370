//Write a program to Recursive reverse number. 
#include <stdio.h>
int reverseNumber(int n, int rev) {
    if (n == 0) {
        return rev;
    } else {
        rev = rev * 10 + n % 10;
        return reverseNumber(n / 10, rev);
    }
}

int main() {
    int num, reversed;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    reversed = reverseNumber(num, 0);
    printf("Reversed number of %d is %d", num, reversed);

    return 0;
}