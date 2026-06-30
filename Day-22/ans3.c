//Write a program to Character frequency.
#include <stdio.h>
int main() {
    char str[100];
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate frequency of each character
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}