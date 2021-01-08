/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** plusieur flags de epitech
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void is_a_showstr_octal(va_list ap, struct nbr_trf *p)
{
    my_showstr_octal(va_arg(ap, char *));
}

void is_a_unsigned_nbr(va_list ap, struct nbr_trf *p)
{
    my_put_nbr_unsigned(va_arg(ap, unsigned));
}

void is_a_pointeur(va_list ap, struct nbr_trf *p)
{
    my_put_padress(va_arg(ap, char *));
}

void is_a_pourcent(va_list ap, struct nbr_trf *p)
{
    int nbr = 0;

    if (my_char_isnum(p->format[0]) == 1)
        nbr = my_getnbr(p->format);
    for (; nbr > 1; nbr--)
        my_putchar(' ');
    my_putchar('%');
}