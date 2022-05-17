#ifndef COFFEE_MACHINE_MAIN_H
#define COFFEE_MACHINE_MAIN_H

/**
 * @file main.h
 * @brief Header file that contains all structures and includes, this file is the only file that is include in others files
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
 * Structure in order to store drinks from file for the program
 */
typedef struct {
    char name[20];
    float price;
    int number;
} struct_drinks;

/**
 * Structure in order to store coins from file for the program
 */
typedef struct {
    float value;
    unsigned int number;
} struct_coins;

/**
 * Structure in order to store coins entered by the user
 */
typedef struct {
    int c05;
    int c1;
    int c2;
    int c5;
} struct_given;

/**
 * Structure in order to store the choice of the user
 */
typedef struct {
    struct_drinks d;
    int type;
    float money;
    struct_given given;
} struct_user;

#include "drinks.h"
#include "money.h"
#include "processing.h"
#include "administration.h"

#endif //COFFEE_MACHINE_MAIN_H