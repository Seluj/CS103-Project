#ifndef COFFEE_MACHINE_ADMINISTRATION_H
#define COFFEE_MACHINE_ADMINISTRATION_H

/**
 * @file administration.h
 * @brief Administration header file
 *
 * Header file that contains all prototypes of function related to administration mode
 * @author Jules F.
 * @date May 2022
 */


/**
 * Function to check if @a a is equal to @a b
 * @param a first parameter
 * @param b second parameter
 * @return return true if there equal, false if not
 */
bool code_check(int a, int b);

/**
 * Print menu for administration mode
 * @return return choice of user
 */
int administration_menu();

/**
 * Function that ask the user to enter the code
 * @return return the code given
 */
bool enter_code();

/**
 * Function that add a drink in the drink list, it modify @a drink and the number of drinks
 * @param drink where to add the new drink
 * @param nb_type number of drink to modify
 * @return return drinks data
 */
struct_drinks *add_drink(struct_drinks *drink, int *nb_type);

/**
 * Function that remove a drink in the list, it modify drink and the number of drinks
 * @param drink where to remove a drink
 * @param nb_type number of drink to modify
 * @return return drinks data
 */
struct_drinks *remove_drink(struct_drinks *drink, int *nb_type);

/**
 * Main part of administration mode, call all others functions
 * @param drink drinks data
 * @param nb_type number of types of drink
 * @return return drinks data
 */
struct_drinks *administration(struct_drinks *drink, int *nb_type);

#endif //COFFEE_MACHINE_ADMINISTRATION_H