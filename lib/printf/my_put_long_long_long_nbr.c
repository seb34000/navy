/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** afichage des long long
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void my_put_long_nbr(long long nb)
{
    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_long_nbr(nb / 10);
        my_put_long_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return ;
}

void my_put_long_long_nbr(long long nb)
{
    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_long_nbr(nb / 10);
        my_put_long_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return ;
}