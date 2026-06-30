//Write a program to Find sum and average of array elements.
#include<stdio.h>

int main() {
    int arr[100], n;
    int sum = 0;
    float average;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    average = (float)sum / n;
    printf("Sum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", average);
    return 0;
}