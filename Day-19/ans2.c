//Write a program to Subtract matrices. 
#include <stdio.h>

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int arr1[rows][cols], arr2[rows][cols], diff[rows][cols];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Subtracting matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // Displaying the difference matrix
    printf("Difference of the matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}