//Write a program to Find column-wise sum. 
#include <stdio.h>

int main() {
    int matrix[10][10], rows, cols, i, j;
    int columnSum[10] = {0}; // Initialize column sums to 0

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculating column-wise sum
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            columnSum[j] += matrix[i][j];
        }
    }

    // Displaying column-wise sum
    printf("Column-wise sum:\n");
    for (j = 0; j < cols; j++) {
        printf("Column %d: %d\n", j + 1, columnSum[j]);
    }

    return 0;
}