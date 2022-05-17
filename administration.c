#include "main.h"

/**
 * @file administration.c
 * @brief Source file contains all functions' definitions related to administrator mode
 * @author Jules F.
 * @date May 2022
 */


bool code_check(int a, int b) {
    bool returned = true;
    if (a != b) {
        returned = false;
    }
    return returned;
}

int administration_menu() {
    int returned = 0;
    do {
        printf("\n\n=== Administration Menu ===\n"
               "\t1 - Add drink\n"
               "\t2 - Remove drink\n"
               "\t3 - Leave\n"
               "Choice :");
        fflush(stdin);
        scanf("%d", &returned);
    } while (returned < 1 || returned > 3);
    return returned;
}

bool enter_code() {
    int a;
    printf("Enter the code to enter in administration mode\n"
           "Code:");
    fflush(stdin);
    scanf("%d", &a);
    while (code_check(a, 1234) == false && a != 0) {
        printf("Wrong code\n"
               "Enter the code to enter in administration mode (0 to canceled)\n"
               "Code:");
        fflush(stdin);
        scanf("%d", &a);
    }
    return code_check(a, 1234);
}

struct_drinks *add_drink(struct_drinks *drink, int *nb_type) {
    struct_drinks added;
    char str[5];
    float tmp;
    printf("Please enter details about the drink:\n"
           "Name (without space):");
    fflush(stdin);
    scanf("%s", added.name);
    printf("Price:");
    fflush(stdin);
    gets(str);
    added.price = parse_float(str);
    tmp = added.price - (int)added.price;
    while ((added.price <= 0 || added.price > 10) || (tmp != 0 && tmp != 0.5)) {
        printf("You need to enter a price between 0.5 and 10\n");
        printf("Price:");
        fflush(stdin);
        gets(str);
        added.price = parse_float(str);
        tmp = added.price - (int)added.price;

    }
    added.number = 50;
    printf("You want to add:\n"
           "%s - %.1f\n", added.name, added.price);
    *nb_type = *nb_type + 1;
    drink = realloc(drink, sizeof(struct_drinks) * *nb_type);
    strcpy(drink[*nb_type-1].name, added.name);
    drink[*nb_type-1].price = added.price;
    drink[*nb_type-1].number = added.number;
    return drink;
}

struct_drinks *remove_drink(struct_drinks *drink, int *nb_type) {
    int j, i;
    FILE *d;
    do {
        printf("\n\nWhich one do you want to remove?\n");
        for (j = 0; j < *nb_type; j++) {
            printf("\t%d - %s\n", j + 1, drink[j].name);
        }
        printf("\t%d - Canceled\n"
               "Choice :", j+1);
        fflush(stdin);
        scanf("%d", &i);
    } while (i < 1 || i > j+1);
    if (i != j+1) {
        *nb_type = *nb_type - 1;
        d = fopen("drinks", "w+");
        fprintf(d, "%d\n", *nb_type);
        for (int k = 0; k < *nb_type + 1; k++) {
            if (k != i-1) {
                fprintf(d, "%s\t%.0f\t%d\n", drink[k].name, drink[k].price, drink[k].number);
            }
        }
        fclose(d);
        free(drink);
        drink = malloc(sizeof(struct_drinks) * *nb_type);
        d = fopen("drinks", "r");
        fscanf(d, "%d\n", nb_type);
        i = 0;
        while (fscanf(d, "%s\t%f\t%d\n", drink[i].name, &drink[i].price, &drink[i].number) != EOF) {
            i++;
        }
        fclose(d);
    }
    return drink;
}

struct_drinks *administration(struct_drinks *drink, int *nb_type) {
    bool code = enter_code();
    int service;
    if (code) {
        do {
            service = administration_menu();
            switch (service) {
                case 1:
                    drink = add_drink(drink, nb_type);
                    break;
                case 2:
                    drink = remove_drink(drink, nb_type);
                    break;
                default:
                    break;
            }
        } while (service != 3);
    }
    return drink;
}