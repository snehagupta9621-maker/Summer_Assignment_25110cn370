//Write a program to Intersection of arrays.
#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int intersection[size1 < size2 ? size1 : size2];
    int i, j, k;

    // Find the intersection of the two arrays
    k = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                intersection[k++] = arr1[i];
                break;
            }
        }
    }

    // Print the intersection array
    printf("Intersection array: ");
    for (i = 0; i < k; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");

    return 0;
}