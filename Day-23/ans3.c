//Write a program to Check anagram strings
#include<stdio.h>
#include<string.h>

int main() {
    char str1[100], str2[100];
    int i, j, found, count1[26] = {0}, count2[26] = {0};

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Count frequency of each character in both strings
    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            count1[str1[i] - 'a']++;
        }
    }
    for(i = 0; str2[i] != '\0'; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z') {
            count2[str2[i] - 'a']++;
        }
    }

    // Check if both strings have same character frequencies
    found = 1;
    for(i = 0; i < 26; i++) {
        if(count1[i] != count2[i]) {
            found = 0;
            break;
        }
    }

    if(found) {
        printf("Strings are anagrams.");
    } else {
        printf("Strings are not anagrams.");
    }

    return 0;
}