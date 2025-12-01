#include <stdio.h>
#include <string.h>

struct Movie {
    int movie_id;
    char name[50];
    int price;
};

struct Booking {
    char customer_name[50];
    char movie_name[50];
    int tickets;
    int total_cost;
    float discount;
    float final_amount;
};

int main() {
    struct Movie movies[3] = {
        {1, "Animal", 250},
        {2, "Bajrangi Bhaijaan", 200},
        {3, "Stranger's Things", 300}
    };

    struct Booking booking;

    int choice, id, i;

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
            printf("\n             Available Movies              \n");
            for (i = 0; i < 3; i++) {
                printf("%d. %s (Price: Rs %d per ticket)\n",
                        movies[i].movie_id, movies[i].name, movies[i].price);
            }
            break;

        case 2:
            printf("\nEnter your name: ");
            scanf(" %[^\n]", booking.customer_name);

            printf("\nEnter Movie ID to Book: ");
            scanf("%d", &id);

            int found = 0;
            for (i = 0; i < 3; i++) {
                if (movies[i].movie_id == id) {
                    found = 1;
                    strcpy(booking.movie_name, movies[i].name);

                    printf("Enter number of tickets: ");
                    scanf("%d", &booking.tickets);

                    booking.total_cost = booking.tickets * movies[i].price;

                    
                    if (booking.tickets >= 3 && booking.tickets <= 5) {
                        booking.discount = booking.total_cost * 0.10;
                    } else if (booking.tickets > 5) {
                        booking.discount = booking.total_cost * 0.20;
                    } else {
                        booking.discount = 0;
                    }

                    booking.final_amount = booking.total_cost - booking.discount;

                    printf("\nTickets booked successfully!\n");
                    break;
                }
            }

            if (!found) {
                printf("Invalid Movie ID!\n");
            }
            break;

        case 3:
            printf("\n.................... BOOKING RECEIPT .....................\n");
            printf("-----------------------------------------------------------\n");
            printf("                    CINEMA WORLD MULTIPLEX\n");
            printf("-----------------------------------------------------------\n");
            printf("Customer Name   : %s\n", booking.customer_name);
            printf("Movie Booked    : %s\n", booking.movie_name);
            printf("Tickets         : %d\n", booking.tickets);
            printf("Cost per Ticket : Rs %d\n", 
                   (strcmp(booking.movie_name, "Avengers: Endgame") == 0) ? 250 :
                   (strcmp(booking.movie_name, "KGF Chapter 2") == 0) ? 200 : 300);

            printf("-----------------------------------------------------------\n");
            printf("Total Cost      : Rs %d\n", booking.total_cost);

            if (booking.discount > 0)
                printf("Discount Applied: Rs %.2f\n", booking.discount);
            else
                printf("Discount Applied: Rs 0.00\n");

            printf("-----------------------------------------------------------\n");
            printf("FINAL AMOUNT    : Rs %.2f\n", booking.final_amount);
            printf("-----------------------------------------------------------\n");
            printf("              THANK YOU! ENJOY YOUR SHOW \n");
            printf("............................................................\n");
            break;

        case 4:
            printf("\nThank you \n");
            return 0;

        default:
            printf("\nInvalid Choice Try again.\n");
        }
    }

    return 0;
}
