//Write a program to Find product of digits. 
#include<stdio.h>
int main(){
    int n, product = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while(n != 0)
    {
        product *= n % 10;
        n /= 10;
    }
    printf("Product of digits: %d", product);
    return 0;
}