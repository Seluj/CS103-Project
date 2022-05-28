#ifndef COFFEE_MACHINE_PROCESSING_H
#define COFFEE_MACHINE_PROCESSING_H

/**
 * @file processing.h
 * @brief Processing header file
 *
 * Header file that contains all others functions' prototypes that are not related to drinks, coins or administration
 * @author Jules F.
 * @date May 2022
 */


/**
 * Initialize the program, check and read files
 * @param drinks structure of drinks, the function save all drinks from file @b drinks to this variable
 * @param coins structure of coins, the function save all coins from file @b coins to this variable
 * @param number_of_coffee number of types of coffee in the file @b drinks
 * @return return a pointer to all drinks saved in variable drinks
 */
struct_drinks *initialisation(struct_drinks *drinks, struct_coins *coins, int *number_of_coffee);

/**
 * Just print information when the program start
 */
void print_info();

/**
 * Save drinks, coins and number of coffee in file for the next program's start
 * @param drinks drinks to save
 * @param coins coins to save
 * @param number_of_coffee number of types of coffee to save
 */
void saving(struct_drinks *drinks, struct_coins coins[number_coin], int number_of_coffee);

/**
 * Reset number of coffee and amount of coins in the machine
 * @param drinks drinks to reset
 * @param coins coins to reset
 * @param number_of_coffee number of types of coffee
 */
void reset(struct_drinks *drinks, struct_coins *coins, int number_of_coffee);

/**
 * That function is an update of the function strlen
 * @param str string to convert in float
 * @return return float number or -1 if there is a problem
 */
float parse_float(char str[5]);

/**
 * Function that clear the input file because sometimes there still have a character and most of the time it is @a \\n
 */
void clear_buffer();

#endif //COFFEE_MACHINE_PROCESSING_H