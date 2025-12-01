#include <stdio.h>
#include <string.h>
#include "movie.h"

void showMovies(struct Movie movies[], int size) {
    printf("\n             Available Movies              \n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s (Price: Rs %d per ticket)\n",
               movies[i].movie_id, movies[i].name, movies[i].price);
    }
}

void bookTicket(struct Movie movies[], int size, struct Booking *booking) {

    printf("\nEnter your name: ");
    scanf(" %[^\n]", booking->customer_name);

    int id, found = 0;
    printf("\nEnter Movie ID to Book: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (movies[i].movie_id == id) {
            found = 1;

            strcpy(booking->movie_name, movies[i].name);

            printf("Enter number of tickets: ");
            scanf("%d", &booking->tickets);

            booking->price_per_ticket = movies[i].price;
            booking->total_cost = booking->tickets * movies[i].price;

            // Discounts
            if (booking->tickets >= 3 && booking->tickets <= 5)
                booking->discount = booking->total_cost * 0.10;
            else if (booking->tickets > 5)
                booking->discount = booking->total_cost * 0.20;
            else
                booking->discount = 0;

            booking->final_amount = booking->total_cost - booking->discount;

            printf("\nTickets booked successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("Invalid Movie ID!\n");
    }
}

void showReceipt(struct Booking booking) {

    printf("\n.................... BOOKING RECEIPT .....................\n");
    printf("-----------------------------------------------------------\n");
    printf("                    CINEMA WORLD MULTIPLEX\n");
    printf("-----------------------------------------------------------\n");

    printf("Customer Name   : %s\n", booking.customer_name);
    printf("Movie Booked    : %s\n", booking.movie_name);
    printf("Tickets         : %d\n", booking.tickets);
    printf("Cost per Ticket : Rs %d\n", booking.price_per_ticket);

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
}
