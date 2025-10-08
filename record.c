/* records.c - Record Handling Module */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
#include "filehandling.h"

MenuItem menu[MAX_MENU];// array of structure declaration   .  declare globally to hold all menu items
int menuCount = 0;

void addMenuItem() {
    if (menuCount >= MAX_MENU) {
        printf("Menu full!\n");
        return;
    }
    printf("Enter Item Code: ");
    scanf("%d", &menu[menuCount].code);
    getchar();
    printf("Enter Item Name: ");
    fgets(menu[menuCount].name, 50, stdin);
    menu[menuCount].name[strcspn(menu[menuCount].name, "\n")] = '\0';
    printf("Enter Price: ");
    scanf("%f", &menu[menuCount].price);
    menuCount++;
    saveMenuToFile();
}

void updateMenuItem() {
    int code, i;
    printf("Enter Item Code to update: ");
    scanf("%d", &code);
    for (i = 0; i < menuCount; i++) {
        if (menu[i].code == code) { 
            getchar();
            printf("Enter New Name: ");
            fgets(menu[i].name, 50, stdin);
            menu[i].name[strcspn(menu[i].name, "\n")] = '\0';
            printf("Enter New Price: ");
            scanf("%f", &menu[i].price);
            saveMenuToFile();
            return;
        }
    }
    printf("Item not found.\n");
}

void displayMenu() {
    loadMenuFromFile(); // this will show the upto date menu.
    printf("\n--- Menu ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d - %s: Rs. %.2f\n", menu[i].code, menu[i].name, menu[i].price);
    }
}

void initializeOrder(Order *order) {//  Before adding items to an order, you want to start fresh with no previous data.
    order->itemCount = 0;
    order->total = 0;//pointer to structure
}

void addItemToOrder(Order *order, int code, int qty) {
    loadMenuFromFile();  //makes sure you have the latest menu data every time you add an item to an order.
    for (int i = 0; i < menuCount; i++) {
        if (menu[i].code == code) {
            order->items[order->itemCount].item = menu[i];
            order->items[order->itemCount].quantity = qty;
            order->itemCount++;
            break;
        }
    }
}

float calculateTotal(Order *order) { 
    float total = 0;
    for (int i = 0; i < order->itemCount; i++) {
        total += order->items[i].item.price * order->items[i].quantity;
    }
    if (total >= 500) total *= 0.9; // 10% discount for orders >= Rs.500
    order->total = total;
    return total;
}
