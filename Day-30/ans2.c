//Write a program to Create mini library system.
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int isAvailable;
};

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int findBookById(struct Book books[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library system is full.\n");
        return;
    }

    struct Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    while (getchar() != '\n');

    if (findBookById(books, *count, newBook.id) != -1) {
        printf("Book ID already exists.\n");
        return;
    }

    printf("Enter book title: ");
    readLine(newBook.title, sizeof(newBook.title));

    printf("Enter book author: ");
    readLine(newBook.author, sizeof(newBook.author));

    newBook.isAvailable = 1;

    books[(*count)++] = newBook;
    printf("Book added successfully.\n");
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n=== Library Books ===\n");
    printf("%-5s %-30s %-25s %-12s\n", "ID", "Title", "Author", "Availability");
    printf("====================================================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-25s %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].isAvailable ? "Available" : "Not Available");
    }
    printf("====================================================================\n\n");
}

void searchBook(struct Book books[], int count) {
    int id;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findBookById(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("\n=== Book Found ===\n");
    printf("ID: %d\n", books[index].id);
    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Status: %s\n\n", books[index].isAvailable ? "Available" : "Not Available");
}

void updateBook(struct Book books[], int count) {
    int id;
    printf("Enter book ID to update: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findBookById(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("Current book details:\n");
    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Status: %s\n\n", books[index].isAvailable ? "Available" : "Not Available");

    printf("Enter new title: ");
    readLine(books[index].title, sizeof(books[index].title));

    printf("Enter new author: ");
    readLine(books[index].author, sizeof(books[index].author));

    printf("Book updated successfully.\n\n");
}

void checkoutBook(struct Book books[], int count) {
    int id;
    printf("Enter book ID to checkout: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findBookById(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (!books[index].isAvailable) {
        printf("Book is not available for checkout.\n\n");
        return;
    }

    books[index].isAvailable = 0;
    printf("Book '%s' checked out successfully.\n\n", books[index].title);
}

void returnBook(struct Book books[], int count) {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findBookById(books, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    if (books[index].isAvailable) {
        printf("This book was not checked out.\n\n");
        return;
    }

    books[index].isAvailable = 1;
    printf("Book '%s' returned successfully.\n\n", books[index].title);
}

void removeBook(struct Book books[], int *count) {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findBookById(books, *count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }
    (*count)--;
    printf("Book removed successfully.\n\n");
}

void displayMenu() {
    printf("\n===============================================\n");
    printf("        MINI LIBRARY MANAGEMENT SYSTEM\n");
    printf("===============================================\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book\n");
    printf("4. Checkout a book\n");
    printf("5. Return a book\n");
    printf("6. Update book details\n");
    printf("7. Remove a book\n");
    printf("8. Exit\n");
    printf("===============================================\n");
    printf("Enter your choice: ");
}

int main() {
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    printf("Welcome to Mini Library Management System!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\n--- Add Book ---\n");
                addBook(books, &bookCount);
                break;

            case 2:
                displayBooks(books, bookCount);
                break;

            case 3:
                printf("\n--- Search Book ---\n");
                searchBook(books, bookCount);
                break;

            case 4:
                printf("\n--- Checkout Book ---\n");
                checkoutBook(books, bookCount);
                break;

            case 5:
                printf("\n--- Return Book ---\n");
                returnBook(books, bookCount);
                break;

            case 6:
                printf("\n--- Update Book ---\n");
                updateBook(books, bookCount);
                break;

            case 7:
                printf("\n--- Remove Book ---\n");
                removeBook(books, &bookCount);
                break;

            case 8:
                printf("Thank you for using Mini Library Management System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
