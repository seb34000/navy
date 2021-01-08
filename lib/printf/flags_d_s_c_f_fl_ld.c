/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** plusieur flags
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void is_a_nbr(va_list ap, struct nbr_trf *p)
{
    char *str = my_put_nbr_char(va_arg(ap, int));

    format_nbr(str, p->format);
}

void is_a_string(va_list ap, struct nbr_trf *p)
{
    format_str(va_arg(ap, char *), p->format);
}

void is_a_char(va_list ap, struct nbr_trf *p)
{
    my_putchar(va_arg(ap, int));
}

void is_a_float(va_list ap, struct nbr_trf *p)
{
    my_put_float_nbr(va_arg(ap, double));
}