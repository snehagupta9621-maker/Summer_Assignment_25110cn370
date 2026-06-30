//Write a program to Create library management system. 
    #include <stdio.h>
    #include <string.h>

    struct Book {
        int id;
        char title[100];
        char author[100];
        int isAvailable;
    };

    int main() {
        struct Book books[100];
        int n = 0;

        int choice;
        do {
            printf("\nLibrary Management System\n");
            printf("1. Add Book Record\n");
            printf("2. Display Book Records\n");
            printf("3. Search Book Record\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter book ID: ");
                    scanf("%d", &books[n].id);
                    printf("Enter book title: ");
                    scanf("%s", books[n].title);
                    printf("Enter book author: ");
                    scanf("%s", books[n].author);
                    books[n].isAvailable = 1;
                    n++;
                    break;
                case 2:
                    printf("Book Records:\n");
                    for(int i = 0; i < n; i++) {
                        printf("ID: %d, Title: %s, Author: %s, Available: %s\n", books[i].id, books[i].title, books[i].author, books[i].isAvailable ? "Yes" : "No");
                    }
                    break;
                case 3:
                    int searchId;
                    printf("Enter book ID to search: ");
                    scanf("%d", &searchId);
                    for(int i = 0; i < n; i++) {
                        if(books[i].id == searchId) {
                            printf("Book record found:\n");
                            printf("ID: %d, Title: %s, Author: %s, Available: %s\n", books[i].id, books[i].title, books[i].author, books[i].isAvailable ? "Yes" : "No");
                            break;
                        }
                    }
                    break;
                case 4:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while(choice != 4);

        return 0;
    }
