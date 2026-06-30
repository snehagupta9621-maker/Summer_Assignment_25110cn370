//Write a program to Find missing number in an array.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the missing number
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += arr[i];
    }

    int missing_number = expected_sum - actual_sum;
    printf("The missing number is: %d\n", missing_number);

    return 0;
}