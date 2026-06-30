//Write a program to Linear search.
#include<stdio.h>

int main() {
    int arr[100], n, search;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &search);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }
    return 0;
}