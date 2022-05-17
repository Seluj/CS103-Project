#ifndef COFFEE_MACHINE_MONEY_H
#define COFFEE_MACHINE_MONEY_H

/**
 * @file money
 * @brief Header file that contains all functions' prototypes related to money
 * @author Jules F.
 * @date May 2022
 */


/**
 * ask the user to enter the right amount of money needed for the drink chosen
 * @param user a pointer to user's data
 * @return return 0 if the user wants to cancel, 1 if user gives the right amount of money and 2 if the user gives more money than needed
 */
int coin_add(struct_user *user);

/**
 * check if the machine can give change
 * @param user user's data
 * @param coins coins' data reduce with coin given to user and increase with coin taken from user
 * @return return true if there is enough change and false if there is a problem
 */
bool check_change(struct_user user, struct_coins coins[]);

#endif //COFFEE_MACHINE_MONEY_H