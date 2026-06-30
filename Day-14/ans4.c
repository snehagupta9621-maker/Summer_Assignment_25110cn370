//Write a program to Find duplicates in array.
#include<stdio.h>

int main() {
    int arr[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int duplicates = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                duplicates++;
                break;
            }
        }
    }
    printf("Number of duplicate elements: %d\n", duplicates);
    return 0;
}