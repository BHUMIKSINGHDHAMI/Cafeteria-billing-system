/* cafeteria_billing_system.c - Main Driver Module */
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include "auth.h"
#include "stringutils.h"
#include "record.h"
#include "filehandling.h"

void showMainMenu() {
    printf("\n---- Cafeteria Billing System ----\n");
    printf("1. Add Menu Item\n");
    printf("2. Update Menu Item\n");
    printf("3. Display Menu\n");
    printf("4. Take Order\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    if (!authenticate()) {
        printf("Authentication Failed. Exiting...\n");
        return 1;
    }

    int choice;
    Order order;
    int code, qty;

    do {
        showMainMenu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMenuItem();
                break;

            case 2:
                updateMenuItem();
                break;

            case 3:
                displayMenu();
                break;

            case 4:
                initializeOrder(&order);
                char cont = 'y';
                while (cont == 'y' || cont == 'Y') {
                    printf("Enter Item Code: ");
                    scanf("%d", &code);
                    printf("Enter Quantity: ");
                    scanf("%d", &qty);
                    addItemToOrder(&order, code, qty);
                    getchar(); // consume newline
                    printf("Add more items? (y/n): ");
                    scanf("%c", &cont);
                    getchar();
                }

                float total = calculateTotal(&order);
                printf("Total Bill: Rs. %.2f\n", total);
                saveOrderToFile(&order);
                break;

            case 5:
                printf("Thank you for using the Cafeteria Billing System!\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
