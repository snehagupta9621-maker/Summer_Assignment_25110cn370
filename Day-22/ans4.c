//Write a program to Remove spaces from a string.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove leading spaces
    for (i = 0; str[i] == ' '; i++);

    // Shift remaining characters to the left
    for (j = 0; str[i] != '\0' && str[i] != '\n'; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0'; // Add null terminator

    printf("String after removing leading spaces: %s", str);

    return 0;
}