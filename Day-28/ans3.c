//Write a program to Create ticket booking system.
#include <stdio.h>
#include <string.h>

struct Ticket {
    int ticketId;
    char passengerName[100];
    char destination[100];
    float price;
};

int main() {
    struct Ticket tickets[100];
    int n = 0;

    int choice;
    do {
        printf("\nTicket Booking System\n");
        printf("1. Book Ticket\n");
        printf("2. Display Ticket Records\n");
        printf("3. Search Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ticket ID: ");
                scanf("%d", &tickets[n].ticketId);
                printf("Enter passenger name: ");
                scanf("%s", tickets[n].passengerName);
                printf("Enter destination: ");
                scanf("%s", tickets[n].destination);
                printf("Enter ticket price: ");
                scanf("%f", &tickets[n].price);
                n++;
                break;
            case 2:
                printf("Ticket Records:\n");
                for(int i = 0; i < n; i++) {
                    printf("Ticket ID: %d, Passenger Name: %s, Destination: %s, Price: %.2f\n", tickets[i].ticketId, tickets[i].passengerName, tickets[i].destination, tickets[i].price);
                }
                break;
            case 3:
                int searchTicketId;
                printf("Enter ticket ID to search: ");
                scanf("%d", &searchTicketId);
                for(int i = 0; i < n; i++) {
                    if(tickets[i].ticketId == searchTicketId) {
                        printf("Ticket record found:\n");
                        printf("Ticket ID: %d, Passenger Name: %s, Destination: %s, Price: %.2f\n", tickets[i].ticketId, tickets[i].passengerName, tickets[i].destination, tickets[i].price);
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