#ifndef MOVIE_H
#define MOVIE_H

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
    int price_per_ticket;
};

// Function declarations
void showMovies(struct Movie movies[], int size);
void bookTicket(struct Movie movies[], int size, struct Booking *booking);
void showReceipt(struct Booking booking);

#endif
