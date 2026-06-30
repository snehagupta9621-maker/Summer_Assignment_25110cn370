//Write a program to Reverse a string. 
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate string length
    length = strlen(str) - 1; // Subtract 1 to exclude newline character

    // Reverse the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s", str);

    return 0;
}