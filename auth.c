/* auth.c - User Authentication Module */
#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "stringutils.h"

#define USERNAME "admin"
#define PASSWORD "admin123"
#define MAX_ATTEMPTS 3

int authenticate() {
    char username[50];
    char password[50];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter Username: ");
        fgets(username, 50, stdin);
       for (int i = 0; username[i] != '\0'; i++) {
    if (username[i] == '\n') {
        username[i] = '\0';
        break;
    }
}

        printf("Enter Password: ");
        fgets(password, 50, stdin);
        password[strcspn(password, "\n")] = '\0';

        if (stringCompare(username, USERNAME) == 0 && stringCompare(password, PASSWORD) == 0) {
            return 1;
        } else {
            attempts++;
            printf("Invalid credentials. Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    printf("Maximum login attempts exceeded. Access denied.\n");
    return 0;
}
