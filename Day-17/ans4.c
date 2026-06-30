//Write a program to Find common elements
#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int common[size1 < size2 ? size1 : size2];
    int i, j, k;

    // Find the common elements of the two arrays
    k = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                common[k++] = arr1[i];
                break;
            }
        }
    }

    // Print the common elements array
    printf("Common elements array: ");
    for (i = 0; i < k; i++) {
        printf("%d ", common[i]);
    }
    printf("\n");

    return 0;
}