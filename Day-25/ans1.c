//Write a program to Merge two sorted arrays. 
#include<stdio.h>

int main() {
    int arr1[100], arr2[100], merged[200], n1, n2, i = 0, j = 0, k = 0;
    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of first array: ");
    for (int l = 0; l < n1; l++) {
        scanf("%d", &arr1[l]);
    }
    printf("Enter the number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of second array: ");
    for (int l = 0; l < n2; l++) {
        scanf("%d", &arr2[l]);
    }
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
    printf("Merged sorted array: ");
    for (int l = 0; l < n1 + n2; l++) {
        printf("%d ", merged[l]);
    }
    printf("\n");
    return 0;
}