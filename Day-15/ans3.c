//Write a program to Rotate array right.
#include<stdio.h>

int main() {
    int arr[100], n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of positions to rotate right: ");
    scanf("%d", &k);
    k = k % n; // Handle cases where k is greater than n
    printf("Array after rotating right by %d positions: ", k);
    for (int i = n - k; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}