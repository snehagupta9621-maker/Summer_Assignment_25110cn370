//Write a program to Check whether a number is palindrome.
#include<stdio.h>
int main(){
    int n, original, reversed = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    original = n;
    while(n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    if(original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);
    return 0;
}