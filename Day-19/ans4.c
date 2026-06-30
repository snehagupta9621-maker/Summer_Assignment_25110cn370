//Write a program to Find diagonal sum.
#include <stdio.h>
int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;

    // Calculating diagonal sums
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j) {
                primaryDiagonalSum += matrix[i][j];
            }
            if (i + j == cols - 1) {
                secondaryDiagonalSum += matrix[i][j];
            }
        }
    }

    printf("Primary Diagonal Sum: %d\n", primaryDiagonalSum);
    printf("Secondary Diagonal Sum: %d\n", secondaryDiagonalSum);

    return 0;
}