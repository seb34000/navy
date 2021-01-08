/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** afichages des nbr unsigned
*/

#include "../include/my.h"
#include "../include/my_printf.h"

int my_put_nbr_unsigned(unsigned nb)
{
    if (nb < 0) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (nb);
}