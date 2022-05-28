#include "main.h"

/**
 * @file money.c
 * @brief Money source file
 *
 * Source file that contains all functions' definitions related to money
 * @author Jules F.
 * @date May 2022
 */

int coin_add(struct_user *user) {
    user->given.c05 = 0;
    user->given.c1 = 0;
    user->given.c2 = 0;
    user->given.c5 = 0;
    float coin, sum = 0;
    char str[5];
    printf("You need to insert %.0f km\n", user->d.price);
    printf("Please insert a coin (0.5, 1, 2 or 5) (0 to cancel):");
    clear_buffer();
    fgets(str, 5, stdin);
    str[strlen(str)-1] = '\0';
    coin = parse_float(str);
    while (coin != 0.5 && coin != 0 && coin != 1 && coin != 2 && coin != 5) {
        printf("You need to insert only 0.5, 1, 2 or 5 km coin\n");
        printf("Please insert a coin (0.5, 1, 2 or 5) (0 to cancel):");
        fgets(str, 5, stdin);
        str[strlen(str)-1] = '\0';
        coin = parse_float(str);
    }
    if (coin == 0) {
        return 0;
    } else if (coin == 0.5) {
        user->given.c05++;
    } else if (coin == 1) {
        user->given.c1++;
    } else if (coin == 2) {
        user->given.c2++;
    } else {
        user->given.c5++;
    }
    sum += coin;
    while (sum < user->d.price) {
        printf("Left: %.1f\n", user->d.price-sum);
        printf("Please insert a coin (0.5, 1, 2 or 5) (0 to cancel):");
        fgets(str, 5, stdin);
        str[strlen(str)-1] = '\0';
        coin = parse_float(str);
        while (coin != 0 && coin != 0.5 && coin != 1 && coin != 2 && coin != 5) {
            printf("You need to insert only 0.5, 1, 2 or 5 km coin\n");
            printf("Please insert a coin (0.5, 1, 2 or 5) (0 to cancel):");
            fgets(str, 5, stdin);
            str[strlen(str)-1] = '\0';
            coin = parse_float(str);
        }
        if (coin == 0) {
            return 0;
        } else if (coin == 0.5) {
            user->given.c05++;
        } else if (coin == 1) {
            user->given.c1++;
        } else if (coin == 2) {
            user->given.c2++;
        } else {
            user->given.c5++;
        }
        sum += coin;
    }
    user->money = sum;
    if (user->money == user->d.price) {
        return 1;
    } else {
        return 2;
    }
}

bool check_change(struct_user user, struct_coins coins[]) {
    int coin_5 = 0, coin_2 = 0, coin_1 = 0, coin_05 = 0;
    int tmp;
    float n1 = user.money-user.d.price;
    bool returned = true;
    while (n1 != 0 && returned == true) {
        returned = false;
        if (n1 >= 5) {
            tmp = (int)n1 / 5;
            if (coins[number_coin-1].number >= tmp) {
                coin_5 = tmp;
                n1 -= (5 * tmp);
                returned = true;
            } else if (coins[number_coin-1].number >= (tmp-1)) {
                coin_5 = tmp-1;
                n1 -= (5 * (tmp-1));
                returned = true;
            }
        }
        if (n1 >= 2) {
            tmp = (int)n1 / 2;
            if (coins[number_coin-2].number >= tmp) {
                coin_2 = tmp;
                n1 -= (2 * tmp);
                returned = true;
            } else if (coins[number_coin-2].number >= (tmp-1)) {
                coin_2 = tmp-1;
                n1 -= (2 * (tmp-1));
                returned = true;
            }
        }
        if (n1 >= 1) {
            tmp = (int)n1 / 1;
            if (coins[number_coin-3].number >= tmp) {
                coin_1 = tmp;
                n1 -= (1 * tmp);
                returned = true;
            } else if (coins[number_coin-3].number >= (tmp-1)) {
                coin_1 = tmp-1;
                n1 -= (1 * (tmp-1));
                returned = true;
            }
        }
        if (n1 >= 0.5) {
            tmp = (int)n1 / 0.5;
            if (coins[number_coin-4].number >= tmp) {
                coin_05 = tmp;
                n1 -= (0.5 * tmp);
                returned = true;
            }
        }
    }


    if (returned == true) {
        for (int j = 0; j < number_coin; j++) {
            if (coins[j].value == 0.5) {
                coins[j].number -= coin_05;
                coins[j].number += user.given.c05;
            } else {
                switch ((int)coins[j].value) {
                    case 1:
                        coins[j].number -= coin_1;
                        coins[j].number += user.given.c1;
                        break;
                    case 2:
                        coins[j].number -= coin_2;
                        coins[j].number += user.given.c2;
                        break;
                    case 5:
                        coins[j].number -= coin_5;
                        coins[j].number += user.given.c5;
                        break;
                }
            }
        }
    }
    return returned;
}