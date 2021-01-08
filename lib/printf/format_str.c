/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** formatage du print
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void format_str(char *str, char *form)
{
    int t = 0;

    if (form[0] == '-') {
        format_str_moins(str, form);
        t++;
    }
    if (form[0] == '+') {
        format_str_plus(str, form);
        t++;
    }
    if (form[0] == '.') {
        format_str_point(str, form);
        t++;
    }
    if (form[0] == ' ')
        my_putchar(' ');
    if (t == 0)
        my_putstr(str);
}

void format_str_plus(char *str, char *form)
{
    int n = my_getnbr(form + 1);

    for (; n > my_strlen(str); n--)
        my_putchar(' ');
    my_putstr(str);
}

void format_str_moins(char *str, char *form)
{
    int n = my_getnbr(form + 1);

    my_putstr(str);
    for (; n > my_strlen(str); n--)
        my_putchar(' ');
}

void format_str_point(char *str, char *form)
{
    int n = my_getnbr(form + 1);

    for (; n > my_strlen(str); n--)
        my_putchar('0');
    my_putstr(str);
}