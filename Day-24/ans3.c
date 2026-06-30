//Write a program to Find longest word. 
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char longest_word[100] = "";
    char *word;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    word = strtok(str, " \n");
    while (word != NULL) {
        if (strlen(word) > strlen(longest_word)) {
            strcpy(longest_word, word);
        }
        word = strtok(NULL, " \n");
    }

    printf("Longest word: %s\n", longest_word);
    return 0;
}