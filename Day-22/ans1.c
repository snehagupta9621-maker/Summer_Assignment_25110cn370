//Write a program to Check palindrome string. 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int length, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate string length
    length = strlen(str) - 1; // Subtract 1 to exclude newline character

    // Convert to lowercase
    for (i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }

    // Check if palindrome
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            printf("The string is not a palindrome.\n");
            return 0;
        }
    }

    printf("The string is a palindrome.\n");

    return 0;
}