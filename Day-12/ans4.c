//Write a program to Write function for perfect number.
#include<stdio.h>

int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isPerfect(n)) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }
    return 0;
}