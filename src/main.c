#include <stdio.h>
#include "movie.h"

int main() {

    struct Movie movies[3] = {
        {1, "Animal", 250},
        {2, "Bajrangi Bhaijaan", 200},
        {3, "Stranger's Things", 300}
    };

    struct Booking booking;
    int choice;

    while (1) {
        printf("\n................... MOVIE TICKET MANAGEMENT SYSTEM  ..................\n");
        printf("1. Show Movies\n");
        printf("2. Book Ticket\n");
        printf("3. Show Booking Receipt\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            showMovies(movies, 3);
            break;

        case 2:
            bookTicket(movies, 3, &booking);
            break;

        case 3:
            showReceipt(booking);
            break;

        case 4:
            printf("\nThank you for using Movie Ticket System!\n");
            return 0;

        default:
            printf("\nInvalid Choice! Try again.\n");
        }
    }

    return 0;
}
