/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** afichage des float
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void my_put_float_nbr(double nb)
{
    int sto = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    sto = my_put_nbr(nb);
    nb -= sto;
    my_putchar('.');
    nb = nb * 10;
    for (int t = 0; t != 6; t++) {
        sto = my_put_nbr(nb);
        nb -= sto;
        nb = nb * 10;
    }
    return ;
}
