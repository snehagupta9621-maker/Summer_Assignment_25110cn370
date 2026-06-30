//Write a program to Frequency of an element. 
#include<stdio.h>

int main() {
    int arr[100], n, search;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to find frequency: ");
    scanf("%d", &search);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            count++;
        }
    }
    printf("Frequency of %d is: %d\n", search, count);
    return 0;
}