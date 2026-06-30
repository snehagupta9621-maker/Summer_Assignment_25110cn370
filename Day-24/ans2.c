//Write a program to Compress a string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 200

// Function to compress string using run-length encoding
void compressString(char *str, char *compressed) {
    int count = 1;
    int index = 0;

    if (str == NULL || str[0] == '\0') {
        compressed[0] = '\0';
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 1] != '\0' && str[i] == str[i + 1]) {
            count++;
        } else {
            compressed[index++] = str[i];
            if (count > 1) {
                if (count >= 10) {
                    compressed[index++] = (count / 10) + '0';
                    compressed[index++] = (count % 10) + '0';
                } else {
                    compressed[index++] = count + '0';
                }
            }
            count = 1;
        }
    }
    compressed[index] = '\0';
}

// Function to decompress a compressed string
void decompressString(char *compressed, char *decompressed) {
    int index = 0;

    if (compressed == NULL || compressed[0] == '\0') {
        decompressed[0] = '\0';
        return;
    }

    for (int i = 0; compressed[i] != '\0'; i++) {
        if (isalpha(compressed[i]) || compressed[i] == ' ') {
            char ch = compressed[i];
            int count = 0;

            // Read the count (can be multi-digit)
            while (compressed[i + 1] != '\0' && isdigit(compressed[i + 1])) {
                i++;
                count = count * 10 + (compressed[i] - '0');
            }

            // If no count found, use 1
            if (count == 0) {
                count = 1;
            }

            // Add character 'count' times
            for (int j = 0; j < count; j++) {
                decompressed[index++] = ch;
            }
        }
    }
    decompressed[index] = '\0';
}

// Function to display compression statistics
void displayCompressionStats(char *original, char *compressed) {
    int originalLen = strlen(original);
    int compressedLen = strlen(compressed);
    float compressionRatio = ((float)(originalLen - compressedLen) / originalLen) * 100;

    printf("\n========================================\n");
    printf("     COMPRESSION STATISTICS\n");
    printf("========================================\n");
    printf("Original length:    %d characters\n", originalLen);
    printf("Compressed length:  %d characters\n", compressedLen);
    printf("Space saved:        %d characters\n", originalLen - compressedLen);
    printf("Compression ratio:  %.2f%%\n", compressionRatio);
    
    if (compressionRatio > 0) {
        printf("Status:             COMPRESSION SUCCESSFUL\n");
    } else {
        printf("Status:             NO COMPRESSION GAIN\n");
    }
    printf("========================================\n\n");
}

// Function to count frequency of characters
void characterFrequency(char *str) {
    int freq[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            freq[(int)tolower(str[i])]++;
        }
    }

    printf("\n========== CHARACTER FREQUENCY ==========\n");
    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d times\n", (char)i, freq[i]);
            count++;
        }
    }
    if (count == 0) {
        printf("No alphabetic characters found.\n");
    }
    printf("==========================================\n\n");
}

// Function to find longest repeated sequence
void findLongestRepeat(char *str) {
    int maxCount = 0;
    char maxChar = '\0';
    int currentCount = 1;

    printf("\n========== REPEATED CHARACTERS ==========\n");
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 1] != '\0' && str[i] == str[i + 1]) {
            currentCount++;
        } else {
            if (currentCount > 1) {
                printf("'%c' appears %d times consecutively\n", str[i], currentCount);
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxChar = str[i];
            }
            currentCount = 1;
        }
    }

    if (maxCount > 1) {
        printf("\nLongest repeat: '%c' appears %d times\n", maxChar, maxCount);
    } else {
        printf("No repeated consecutive characters found.\n");
    }
    printf("==========================================\n\n");
}

// Function to display menu
void displayMenu() {
    printf("\n=================================================\n");
    printf("       STRING COMPRESSION UTILITY\n");
    printf("=================================================\n");
    printf("1. Compress a string (Run-length encoding)\n");
    printf("2. Decompress a string\n");
    printf("3. Show compression statistics\n");
    printf("4. Character frequency analysis\n");
    printf("5. Find repeated characters\n");
    printf("6. Compare original vs compressed\n");
    printf("7. Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
}

int main() {
    char original[MAX_STRING_LENGTH];
    char compressed[MAX_STRING_LENGTH];
    char decompressed[MAX_STRING_LENGTH];
    int choice;
    int operationDone = 0;

    printf("\n========================================\n");
    printf("    WELCOME TO STRING COMPRESSION UTILITY\n");
    printf("========================================\n\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("\nEnter a string to compress: ");
                fgets(original, sizeof(original), stdin);
                original[strcspn(original, "\n")] = '\0';

                if (strlen(original) == 0) {
                    printf("Invalid input. String cannot be empty.\n");
                    break;
                }

                compressString(original, compressed);
                printf("\nOriginal string:   %s\n", original);
                printf("Compressed string: %s\n\n", compressed);
                operationDone = 1;
                break;

            case 2:
                if (!operationDone) {
                    printf("\nPlease compress a string first (Option 1).\n");
                    break;
                }

                decompressString(compressed, decompressed);
                printf("\nCompressed string:   %s\n", compressed);
                printf("Decompressed string: %s\n\n", decompressed);
                break;

            case 3:
                if (!operationDone) {
                    printf("\nPlease compress a string first (Option 1).\n");
                    break;
                }

                displayCompressionStats(original, compressed);
                break;

            case 4:
                if (!operationDone) {
                    printf("\nPlease compress a string first (Option 1).\n");
                    break;
                }

                characterFrequency(original);
                break;

            case 5:
                if (!operationDone) {
                    printf("\nPlease compress a string first (Option 1).\n");
                    break;
                }

                findLongestRepeat(original);
                break;

            case 6:
                if (!operationDone) {
                    printf("\nPlease compress a string first (Option 1).\n");
                    break;
                }

                printf("\n========== COMPARISON ==========\n");
                printf("Original string:\n");
                printf("  Content: %s\n", original);
                printf("  Length:  %lu characters\n", strlen(original));
                printf("\nCompressed string:\n");
                printf("  Content: %s\n", compressed);
                printf("  Length:  %lu characters\n", strlen(compressed));
                printf("==============================\n\n");
                break;

            case 7:
                printf("Thank you for using String Compression Utility. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}