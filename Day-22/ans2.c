//Write a program to Count words in a ssentence.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int words = 1; // Initialize to 1 to account for the first word
    int i;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ') {
            words++;
        }
    }

    printf("Number of words: %d\n", words);

    return 0;
}