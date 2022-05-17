#include "main.h"

/**
 * @file main.c
 * @brief Main file of the program, it contains only main function
 * @author Jules F.
 * @date May 2022
 */


int main(void) {
    //all variable that we need during program
    struct_drinks *d; //pointer because we don't know how many types of drinks there are and the size of memory could change during the program
    struct_coins c[number_coin];
    struct_user u;
    int nb_coffee;
    int service1, service2;
    //first we need to initialize all variables that we need like the list of drinks, list of coins and the number of types of coffee
    d = initialisation(d, c, &nb_coffee);
    //if function initialisation return NULL, there is a problem somewhere we need to stop the program here
    if (d == NULL) {
        printf("\n\nHouston, we have a problem\n\n");
        return 1;
    }
    //some info to print
    print_info();

    //main part of the program that end when the user decide to stop it
    do {
        service1 = drink_menu(d, nb_coffee, &u);
        if (service1 == 0) {
            //user wants a drink
            if (check_drink(u)) {
                service2 = coin_add(&u);
                if (service2 == 1) {
                    printf("You give exact amount of money\n"
                           "There is your drink\n");
                    check_change(u, c);
                    d[u.type].number--;
                } else if (service2 == 0) {
                    printf("You canceled your order\n");
                } else if (service2 == 2) {
                    if (check_change(u, c)) {
                        printf("There is enough change for you\n"
                               "Please take your money and your drink\n");
                        d[u.type].number--;
                    }
                }
            }
        } else if (service1 == 1) {
            //user ask for administrator mode
            d = administration(d, &nb_coffee);
        } else if (service1 == 2) {
            //user ask for reset number of coins and coffees
            reset(d, c, nb_coffee);
        } else if (service1 == 36) {
            //there is a problem somewhere
            printf("\n\nHouston, we have a problem\n\n");
            return 1;
        }
    } while (service1 != 3);
    saving(d, c, nb_coffee);
    free(d);
    return 0;
}