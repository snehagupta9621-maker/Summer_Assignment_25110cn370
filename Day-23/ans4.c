//Write a program to Find maximum occurring character.
#include<stdio.h>
int main() {
    char str[100];
    int i, j, maxCount = 0;
    char maxChar;
    printf("Enter a string: ");
    scanf("%s", str);
    for(i = 0; str[i] != '\0'; i++) {
        int count = 1;
        for(j = i + 1; str[j] != '\0'; j++) {
            if(str[i] == str[j]) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            maxChar = str[i];
        }
    }
    printf("Maximum occurring character: %c", maxChar);
    return 0;
} 