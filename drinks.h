#ifndef COFFEE_MACHINE_DRINKS_H
#define COFFEE_MACHINE_DRINKS_H

/**
 * @file drinks.h
 * @brief Drinks header file
 *
 * Header file that contains all prototypes of functions that are related to drinks
 * @author Jules F.
 * @date May 2022
 */


/**
 * Print a menu who ask the user to enter which drink he wants
 * @param drink drinks available
 * @param nb_drink number of drink available
 * @param user data of the user's drinks
 * @return return 0 if nothing wrong, 1 if the user wants to enter in administration mode, 2 if the user chooses to reset data, 2 if the user chooses to quit and 36 if there is a problem
 */
int drink_menu(struct_drinks drink[], int nb_drink, struct_user *user);

/**
 * Check if the drink chosen is out of stock or not
 * @param user user data
 * @return true if all OK and false if the drink is out of stock
 */
bool check_drink(struct_user user);

#endif //COFFEE_MACHINE_DRINKS_H