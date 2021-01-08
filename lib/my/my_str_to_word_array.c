/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../include/my.h"

int if_alpha(char c)
{
    if (c == '.' || c == 'o')
        return (1);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int compteur(char const *str)
{
    int mot = 0;
    int com = 0;

    for (int t = 0; str[t] != '\0'; t++) {
        if (if_alpha(str[t]) == 1)
            mot = 1;
        else {
            if (mot == 1)
                com++;
            mot = 0;
        }
    }
    return (com);
}

char **calcul(char const *str)
{
    int com = 0;
    char **mot;
    int gt = 0;

    mot = malloc(sizeof(char *) * (compteur(str) + 2));
    for (int t = 0;str[t] != '\0'; t++) {
        if (if_alpha(str[t]) == 1)
            com++;
        else {
            if (com > 0) {
                mot[gt] = malloc(sizeof(char) * (com) + 2);
                gt++;
            }
            com = 0;
        }
    }
    mot[gt] = malloc(sizeof(char) * (com + 2));
    return (mot);
}

char **end(char **sto, int gt)
{
    if (sto[gt][0] == ' ' || sto[gt][0] == '\0')
        sto[gt] = NULL;
    else
        sto[gt+1] = NULL;
    return sto;
}

char **my_str_to_word_array(char const *str)
{
    char **sto = calcul(str);
    int mot = 0;
    int pt = 0;
    int gt = 0;

    for (int t = 0; str[t] != '\0'; t += 1) {
        if (if_alpha(str[t]) == 1) {
            mot = 1;
            sto[gt][pt] = str[t];
            pt++;
            sto[gt][pt] = '\0';
        } else {
            if (mot > 0)
                gt++;
            pt = 0;
            mot = 0;
        }
    }
    sto = end(sto, gt);
    return (sto);
}