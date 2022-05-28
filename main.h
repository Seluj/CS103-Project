#ifndef COFFEE_MACHINE_MAIN_H
#define COFFEE_MACHINE_MAIN_H

/**
 * @mainpage
 * @section intro Introduction
 * There is a documentation for the coffee machine program who can be find <a href="https://replit.com/join/rpwdsdmxcw-seluj78" target="_blank">here</a> or on <a href="https://github.com/Seluj/CS103-Project" target="_blank">Github</a>. \n Made by Jules F. alias Seluj78
 */


/**
 * @file main.h
 * @brief Main header file
 *
 * Header file that contains all structures and includes. This file is the only file that is include in others files
 * @author Jules F.
 * @date May 2022
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define number_coin 4

/**
 * @brief Drink structure
 *
 * Structure in order to store drinks from file for the program
 */
typedef struct {
    /** @brief Name of the coffee */
    char name[20];
    /** @brief Coffee's price */
    float price;
    /** @brief Number of drinks remaining */
    int number;
} struct_drinks;

/**
 * @brief Coin structure
 * 
 * Structure in order to store coins from file for the program
 */
typedef struct {
    /** @brief Value of a coin */
    float value;
    /** @brief Number of coins remaining */
    unsigned int number;
} struct_coins;

/**
 * @brief Money given structure
 *
 * Structure in order to store coins entered by the user
 */
typedef struct {
    /** @brief number of 0.5 coins */
    int c05;
    /** @brief number of 1 coins */
    int c1;
    /** @brief number of 2 coins */
    int c2;
    /** @brief number of 5 coins */
    int c5;
} struct_given;

/**
 * @brief User's choice structure
 *
 * Structure in order to store the choice of the user
 */
typedef struct {
    /** @brief Drink chosen by the user */
    struct_drinks d;
    /** @brief Type of the drink by its digit in the list */
    int type;
    /** @brief Total amount of money that the user gives */
    float money;
    /** @brief All coins that the user gives in order to increase amount of coins in the machine */
    struct_given given;
} struct_user;

#include "drinks.h"
#include "money.h"
#include "processing.h"
#include "administration.h"

#endif //COFFEE_MACHINE_MAIN_H