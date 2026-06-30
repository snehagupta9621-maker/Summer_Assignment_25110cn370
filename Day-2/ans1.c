//Write a program to Find sum of digits of a number.
#include<stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while(n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum of digits: %d", sum);
    return 0;
}