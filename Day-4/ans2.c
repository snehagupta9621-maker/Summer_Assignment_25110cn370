//Write a program to Find nth Fibonacci term. 
#include <stdio.h>

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the position of the Fibonacci term you want to find: ");
    scanf("%d", &n);

    if (n == 1) {
        printf("The %dth Fibonacci term is: %d", n, t1);
    } else if (n == 2) {
        printf("The %dth Fibonacci term is: %d", n, t2);
    } else {
        for (i = 3; i <= n; ++i) {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
        printf("The %dth Fibonacci term is: %d", n, t2);
    }

    return 0;
}