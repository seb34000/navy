/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** afiche l'adresse dune variable
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void my_put_padress(void const *p)
{
    long long t = (long long) p;

    my_putstr("0x");
    my_printf("%x", t);
}