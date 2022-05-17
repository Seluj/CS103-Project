#ifndef COFFEE_MACHINE_PROCESSING_H
#define COFFEE_MACHINE_PROCESSING_H

/**
 * @file processing.h
 * @brief Header file that contains all others functions' prototypes that are not related to drinks, coins or administration
 * @author Jules F.
 * @date May 2022
 */


/**
 * Initialiaze the program, check and read files
 * @param drinks structure of drinks, the function save all drinks from file "drinks" to this variable
 * @param coins structure of coins, the function save all coins from file "coins" to this variable
 * @param number_of_coffee number of types of coffee in the file "drinks"
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
 * reset number of coffee and amount of coins in the machine
 * @param drinks drinks to reset
 * @param coins coins to reset
 * @param number_of_coffee number of types of coffee
 */
void reset(struct_drinks *drinks, struct_coins *coins, int number_of_coffee);

/**
 * that function is a uprade of strlen function
 * @param str string to convert in float
 * @return return float number or -1 if there is a problem
 */
float parse_float(char str[5]);

#endif //COFFEE_MACHINE_PROCESSING_H