//Write a program to Create menu-driven string operations system. 
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[50];
    int choice, len, i, pos;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    printf("Menu-Driven String Operations\n");
    printf("1. Find Length\n");
    printf("2. Concatenate Strings\n");
    printf("3. Copy String\n");
    printf("4. Search Substring\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            len = strlen(str);
            printf("Length of the string: %d\n", len);
            break;
        case 2:
            printf("Enter another string to concatenate: ");
            scanf("%s", substr);
            strcat(str, substr);
            printf("Concatenated string: %s\n", str);
            break;
        case 3:
            printf("Enter the string to copy: ");
            scanf("%s", substr);
            strcpy(str, substr);
            printf("Copied string: %s\n", str);
            break;
        case 4:
            printf("Enter the substring to search: ");
            scanf("%s", substr);
            pos = strstr(str, substr) - str;
            if(pos >= 0) {
                printf("Substring found at position: %d\n", pos);
            } else {
                printf("Substring not found.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}