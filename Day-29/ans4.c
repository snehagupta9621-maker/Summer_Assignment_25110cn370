// Write a program to create an inventory management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int findItemById(struct Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addItem(struct Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    struct Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    while (getchar() != '\n');

    if (findItemById(items, *count, newItem.id) != -1) {
        printf("Item ID already exists.\n");
        return;
    }

    printf("Enter item name: ");
    readLine(newItem.name, sizeof(newItem.name));

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    while (getchar() != '\n');

    printf("Enter price: ");
    scanf("%f", &newItem.price);
    while (getchar() != '\n');

    items[(*count)++] = newItem;
    printf("Item added successfully.\n");
}

void displayInventory(struct Item items[], int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n",
               items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItem(struct Item items[], int count) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findItemById(items, count, id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    int choice;
    printf("1. Update quantity\n2. Update price\nChoose: ");
    scanf("%d", &choice);
    while (getchar() != '\n');

    if (choice == 1) {
        printf("Enter new quantity: ");
        scanf("%d", &items[index].quantity);
    } else if (choice == 2) {
        printf("Enter new price: ");
        scanf("%f", &items[index].price);
    } else {
        printf("Invalid choice.\n");
    }

    printf("Item updated successfully.\n");
}

void deleteItem(struct Item items[], int count) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    int index = findItemById(items, count, id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    printf("Item deleted successfully.\n");
}

int main() {
    struct Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                updateItem(inventory, count);
                break;
            case 4:
                deleteItem(inventory, count);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}