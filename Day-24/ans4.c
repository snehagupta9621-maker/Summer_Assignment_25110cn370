//Write a program to Remove duplicate characters.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 200

// Function to remove duplicate characters (preserves order)
void removeDuplicates(char *str) {
    int index = 0;
    int hash[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (hash[(unsigned char)str[i]] == 0) {
            hash[(unsigned char)str[i]] = 1;
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

// Function to remove duplicates (case-insensitive)
void removeDuplicatesCaseInsensitive(char *str, char *result) {
    int index = 0;
    int hash[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);
        if (hash[(unsigned char)ch] == 0) {
            hash[(unsigned char)ch] = 1;
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
}

// Function to find and display duplicate characters
void findDuplicates(char *str) {
    int freq[256] = {0};
    int found = 0;

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("\n========== DUPLICATE CHARACTERS ==========\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            if (isprint(i)) {
                printf("'%c' appears %d times\n", (char)i, freq[i]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No duplicate characters found.\n");
    }
    printf("==========================================\n\n");
}

// Function to count total duplicates
int countDuplicates(char *str) {
    int freq[256] = {0};
    int duplicateCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            duplicateCount += (freq[i] - 1);
        }
    }

    return duplicateCount;
}

// Function to count unique characters
int countUniqueCharacters(char *str) {
    int hash[256] = {0};
    int uniqueCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (hash[(unsigned char)str[i]] == 0) {
            hash[(unsigned char)str[i]] = 1;
            uniqueCount++;
        }
    }

    return uniqueCount;
}

// Function to display detailed statistics
void displayStatistics(char *original, char *processed) {
    int originalLen = strlen(original);
    int processedLen = strlen(processed);
    int duplicatesRemoved = originalLen - processedLen;
    int uniqueCount = countUniqueCharacters(original);

    printf("\n========== STATISTICS ==========\n");
    printf("Original length:      %d characters\n", originalLen);
    printf("After removing dups:  %d characters\n", processedLen);
    printf("Duplicates removed:   %d characters\n", duplicatesRemoved);
    printf("Unique characters:    %d\n", uniqueCount);
    printf("Compression ratio:    %.2f%%\n", ((float)duplicatesRemoved / originalLen) * 100);
    printf("================================\n\n");
}

// Function to remove duplicates but keep last occurrence
void removeDuplicatesKeepLast(char *str, char *result) {
    int hash[256] = {0};
    int len = strlen(str);

    // Mark first occurrence of each character
    for (int i = 0; i < len; i++) {
        hash[(unsigned char)str[i]]++;
    }

    // Copy only last occurrence of each character
    for (int i = 0; i < len; i++) {
        if (hash[(unsigned char)str[i]] > 0) {
            // Check if this is the last occurrence
            int isLast = 1;
            for (int j = i + 1; j < len; j++) {
                if (str[j] == str[i]) {
                    isLast = 0;
                    break;
                }
            }
            if (isLast) {
                result[strlen(result)] = str[i];
                result[strlen(result) + 1] = '\0';
            }
        }
    }
}

// Function to compare two strings ignoring duplicates
int compareWithoutDuplicates(char *str1, char *str2) {
    char copy1[MAX_STRING_LENGTH], copy2[MAX_STRING_LENGTH];
    strcpy(copy1, str1);
    strcpy(copy2, str2);

    removeDuplicates(copy1);
    removeDuplicates(copy2);

    return strcmp(copy1, copy2) == 0;
}

// Function to display menu
void displayMenu() {
    printf("\n=================================================\n");
    printf("    DUPLICATE CHARACTER REMOVAL UTILITY\n");
    printf("=================================================\n");
    printf("1. Remove duplicate characters (preserve order)\n");
    printf("2. Remove duplicates (case-insensitive)\n");
    printf("3. Find and display all duplicates\n");
    printf("4. Show detailed statistics\n");
    printf("5. Remove duplicates (keep last occurrence)\n");
    printf("6. Compare two strings (ignoring duplicates)\n");
    printf("7. Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
}

int main() {
    char original[MAX_STRING_LENGTH];
    char processed[MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH];
    int choice;
    int operationDone = 0;

    printf("\n==========================================\n");
    printf("  DUPLICATE CHARACTER REMOVAL UTILITY\n");
    printf("==========================================\n\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = '\0';

                if (strlen(original) == 0) {
                    printf("Invalid input. String cannot be empty.\n");
                    break;
                }

                strcpy(processed, original);
                removeDuplicates(processed);

                printf("\nOriginal string:  %s\n", original);
                printf("After removing:   %s\n\n", processed);
                operationDone = 1;
                break;

            case 2:
                printf("\nEnter a string: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = '\0';

                if (strlen(original) == 0) {
                    printf("Invalid input. String cannot be empty.\n");
                    break;
                }

                removeDuplicatesCaseInsensitive(original, result);

                printf("\nOriginal string:  %s\n", original);
                printf("After removing (case-insensitive): %s\n\n", result);
                operationDone = 1;
                break;

            case 3:
                printf("\nEnter a string: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = '\0';

                if (strlen(original) == 0) {
                    printf("Invalid input. String cannot be empty.\n");
                    break;
                }

                printf("\nString: %s\n", original);
                findDuplicates(original);
                operationDone = 1;
                break;

            case 4:
                if (!operationDone) {
                    printf("\nPlease process a string first (Option 1-3).\n");
                    break;
                }

                displayStatistics(original, processed);
                break;

            case 5:
                printf("\nEnter a string: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = '\0';

                if (strlen(original) == 0) {
                    printf("Invalid input. String cannot be empty.\n");
                    break;
                }

                memset(result, 0, sizeof(result));
                removeDuplicatesKeepLast(original, result);

                printf("\nOriginal string:  %s\n", original);
                printf("Keep last occurrence: %s\n\n", result);
                operationDone = 1;
                break;

            case 6:
                {
                    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
                    
                    printf("\nEnter first string: ");
                    fgets(str1, sizeof(str1), stdin);
                    str1[strcspn(str1, "\n")] = '\0';

                    printf("Enter second string: ");
                    fgets(str2, sizeof(str2), stdin);
                    str2[strcspn(str2, "\n")] = '\0';

                    if (strlen(str1) == 0 || strlen(str2) == 0) {
                        printf("Invalid input. Strings cannot be empty.\n");
                        break;
                    }

                    if (compareWithoutDuplicates(str1, str2)) {
                        printf("\nThe strings are EQUAL when ignoring duplicates.\n\n");
                    } else {
                        printf("\nThe strings are DIFFERENT when ignoring duplicates.\n\n");
                    }
                }
                break;

            case 7:
                printf("Thank you for using Duplicate Character Removal Utility. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}