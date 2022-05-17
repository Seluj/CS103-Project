#include "main.h"

/**
 * @file processing.c
 * @brief Source file that contains all others functions' definition that are not related to drinks, coins or administration
 * @author Jules F.
 * @date May 2022
 */


struct_drinks *initialisation(struct_drinks *drinks, struct_coins *coins, int *number_of_coffee) {
    FILE *d, *m;
    int i = 0, j = 0;
    d = fopen("drinks", "r");
    m = fopen("money", "r");
    if (d == NULL || m == NULL) {
        fclose(m);
        fclose(d);
        return NULL;
    }
    fscanf(d, "%d\n", number_of_coffee);
    drinks = malloc(sizeof(struct_drinks) * *number_of_coffee);
    while (fscanf(d, "%s\t%f\t%d\n", drinks[i].name, &drinks[i].price, &drinks[i].number) != EOF) {
        i++;
    }
    while (fscanf(m, "%f\t%d\n", &coins[j].value, &coins[j].number) != EOF) {
        j++;
    }
    fclose(m);
    fclose(d);
    return drinks;
}

void print_info() {
    printf("\n\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 62; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf(""
           "**                                                          **\n"
           "**                 ");
    printf("Coffee machine emulation");
    printf("                 **\n"
           "**                                                          **\n"
           "**                         ");
    printf("By Jules");
    printf("                         **\n"
           "**                                                          **\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 62; ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}

void saving(struct_drinks *drinks, struct_coins coins[number_coin], int number_of_coffee) {
    FILE *d, *m;
    if (drinks != NULL) {
        d = fopen("drinks", "w+");
        fprintf(d, "%d\n", number_of_coffee);
        for (int i = 0; i < number_of_coffee; i++) {
            for (int j = 0; j < 20; ++j) {
                if (drinks[i].name[j] == ' ') {
                    drinks[i].name[j] = '_';
                }
            }
            fprintf(d, "%s\t%.0f\t%d\n", drinks[i].name, drinks[i].price, drinks[i].number);
        }
        fclose(d);
    }
    if (coins != NULL) {
        m = fopen("money", "w+");
        for (int i = 0; i < number_coin; i++) {
            fprintf(m, "%.1f\t%d\n", coins[i].value, coins[i].number);
        }
        fclose(m);
    }
}

void reset(struct_drinks *drinks, struct_coins *coins, int number_of_coffee) {
    for (int i = 0; i < number_of_coffee; i++) {
        drinks[i].number = 50;
    }
    for (int i = 0; i < number_coin; i++) {
        coins[i].number = 50;
    }
}

float parse_float(char str[5]) {
    int length = (int)strlen(str);
    int i = 0;
    int error = 0;
    while (error == 0 && i < length) {
        if (str[i] == ',' || str[i] == '.') {
            str[i] = 46;
        } else if (str[i] < 48 || str[i] > 57) {
            error = 1;
        }
        i++;
    }
    if (error == 1) {
        printf("Error, you can use only number\n");
        return -1;
    } else {
        return strtof(str, NULL);
    }
}