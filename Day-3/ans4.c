//Write a program to Find LCM of two numbers.
#include <stdio.h>
int main() {
    int n1, n2, lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    // Ensure both numbers are positive
    if (n1 < 0) n1 = -n1;
    if (n2 < 0) n2 = -n2;

    // Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    int gcd = n1;
    int temp_n2 = n2; // Store original value of n2 for LCM calculation

    while (gcd != temp_n2) {
        if (gcd > temp_n2)
            gcd -= temp_n2;
        else
            temp_n2 -= gcd;
    }

    lcm = (n1 * n2) / gcd;
    printf("LCM = %d", lcm);

    return 0;
}