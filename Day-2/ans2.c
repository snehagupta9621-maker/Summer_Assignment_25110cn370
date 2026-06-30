//Write a program to Reverse a number. 
#include<stdio.h>
int main(){
    int n, reversed = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while(n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    printf("Reversed number: %d", reversed);
    return 0;
}