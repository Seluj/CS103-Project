#include "main.h"

/**
 * @file drink.c
 * @brief Source file that contains all definitions of functions that are related to drinks
 * @author Jules F.
 * @date May 2022
 */


int drink_menu(struct_drinks drink[], const int nb_drink, struct_user *user) {
    int i = 0, j = 0;
    do {
        fflush(stdin);
        printf("\n\n=== Choice of drinks: ===\n");
        for (j = 0; j < nb_drink; j++) {
            printf("\t%d - ", j+1);
            for (int k = 0; k < 20; k++) {
                if (drink[j].name[k] == '_') {
                    drink[j].name[k] = ' ';
                }
            }
            printf("%s - %.1fkm\n", drink[j].name, drink[j].price);
        }
        printf("\t%d - Administration\n"
               "\t%d - Reset\n"
               "\t%d - Exit\n"
               "Choice :", j+1, j+2, j+3);
        fflush(stdin);
        scanf("%d", &i);
    } while (i < 1 || i > j+3);

    if (i <= nb_drink) {
        user->d = drink[i-1];
        user->type = i-1;
    } else if (i == j+1) {
        return 1;
    } else if (i == j+2) {
        return 2;
    } else if (i == j+3) {
        return 3;
    } else {
        return 36;
    }
    return 0;
}

bool check_drink(struct_user user) {
    if (user.d.number > 0) {
        return true;
    } else {
        printf("Sorry we don’t have this coffee any more, we have other types\n");
        return false;
    }
}