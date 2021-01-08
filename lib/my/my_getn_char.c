/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** my_swap.c
*/

#include "../include/my.h"

char *my_getn(char *str, int p, int nbchar)
{
    char *sto = malloc(sizeof(char) * (nbchar + 1));
    int t = 0;

    for (; nbchar != 0 && str[p+t] != '\0'; nbchar--, t++)
        sto[t] = str[p+t];
    sto[t] = '\0';
    return (sto);
}