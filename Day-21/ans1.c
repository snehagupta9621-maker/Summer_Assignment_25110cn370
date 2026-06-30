//Write a program to Find string length without strlen(). 
#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate string length without using strlen()
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        length++;
    }

    printf("Length of the string: %d\n", length);

    return 0;
}