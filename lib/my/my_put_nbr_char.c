/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "../include/my.h"

char *my_put_nbr_char(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int t = 0;
    int neg = 0;

    my_memset(str, 11, '\0');
    if (nb < 0) {
        nb = -nb;
        neg = 1;
    }
    for (;nb > 9; t++) {
        str[t] = ((nb % 10) + '0');
        nb = nb / 10;
    }
    str[t] = ((nb % 10) + '0');
    if (neg == 1)
        str[t + 1] = '-';
    str = my_revstr(str);
    return (str);
}