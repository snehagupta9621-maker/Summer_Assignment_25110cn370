//Write a program to Create menu-driven array operation system.
#include <stdio.h>
int main() {
    int arr[100], n, i, choice, element, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Menu-Driven Array Operations\n");
    printf("1. Display Array\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Search Element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Array Elements: ");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert (0 to %d): ", n);
            scanf("%d", &position);
            if(position < 0 || position > n) {
                printf("Invalid position.\n");
            } else {
                for(i = n; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position] = element;
                n++;
                printf("Element inserted successfully.\n");
            }
            break;
        case 3:
            printf("Enter the position to delete (0 to %d): ", n - 1);
            scanf("%d", &position);
            if(position < 0 || position >= n) {
                printf("Invalid position.\n");
            } else {
                for(i = position; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully.\n");
            }
            break;
        case 4:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            int found = 0;
            for(i = 0; i < n; i++) {
                if(arr[i] == element) {
                    found = 1;
                    break;
                }
            }
            if(found) {
                printf("Element found in the array.\n");
            } }