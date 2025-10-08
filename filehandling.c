/* file_handler.c - File Handling Module */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

extern MenuItem menu[MAX_MENU];
extern int menuCount;

void saveMenuToFile() {
    FILE *fp = fopen("menu.dat", "wb");
    if (fp == NULL) {
        printf("Error saving menu.\n");
        return;
    }
    fwrite(&menuCount, sizeof(int), 1, fp);
    fwrite(menu, sizeof(MenuItem), menuCount, fp);
    fclose(fp);
}

void loadMenuFromFile() {
    FILE *fp = fopen("menu.dat", "rb");
    if (fp == NULL) return;
    fread(&menuCount, sizeof(int), 1, fp);
    fread(menu, sizeof(MenuItem), menuCount, fp);
    fclose(fp);
}

void saveOrderToFile(Order *order) {
    FILE *fp = fopen("orders.txt", "a");// previous record will be save every time
    if (fp == NULL) {
        printf("Error saving order.\n");
        return;
    }
    fprintf(fp, "Order Summary:\n");
    for (int i = 0; i < order->itemCount; i++) {
        fprintf(fp, "%s x%d - Rs. %.2f\n", order->items[i].item.name, order->items[i].quantity,
                order->items[i].item.price * order->items[i].quantity);
    }
    fprintf(fp, "Total: Rs. %.2f\n\n", order->total);
    fclose(fp);
}
