//Write a program to Find GCD of two numbers.
#include <stdio.h>

int main() {
    int n1, n2, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    // Ensure both numbers are positive
    if (n1 < 0) n1 = -n1;
    if (n2 < 0) n2 = -n2;

    // Find GCD
    while (n1 != n2) {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }

    gcd = n1;
    printf("GCD = %d", gcd);

    return 0;
}