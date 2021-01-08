/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** flags de convertion de base
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void is_a_dec_to_hex(va_list ap, struct nbr_trf *p)
{
    char *str = my_dec_to_hex(va_arg(ap, long long));

    if (p->format[0] == '#')
        str = my_strcpy("0x", str);
    my_putstr(str);
}

void is_a_dec_to_hex_maj(va_list ap, struct nbr_trf *p)
{
    char *str = my_dec_to_hex_maj(va_arg(ap, long long));

    if (p->format[0] == '#')
        str = my_strcpy("0X", str);
    my_putstr(str);
}

void is_a_dec_to_oct(va_list ap, struct nbr_trf *p)
{
    char *str = my_dec_to_oct(va_arg(ap, long long));

    if (p->format[0] == '#')
        str = my_strcpy("0", str);
    my_putstr(str);
}

void is_a_dec_to_bin(va_list ap, struct nbr_trf *p)
{
    char *str = my_dec_to_bin(va_arg(ap, long long));

    if (p->format[0] == '#')
        str = my_strcpy("0", str);
    my_putstr(str);
}