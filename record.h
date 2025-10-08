/* records.h - Header for Record Handling Module */
#ifndef RECORDS_H
#define RECORDS_H 

#define MAX_MENU 100
#define MAX_ORDER_ITEMS 20

typedef struct {
    int code;
    char name[50]; 
    float price;
} MenuItem;

typedef struct {
    MenuItem item; // structure within structure
    int quantity;
} OrderItem;

typedef struct {
    OrderItem items[MAX_ORDER_ITEMS];
    int itemCount;
    float total;
} Order;

void addMenuItem();
void updateMenuItem();
void displayMenu();
void initializeOrder(Order *order);
void addItemToOrder(Order *order, int code, int quantity);
float calculateTotal(Order *order);
#endif