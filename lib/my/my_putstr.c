/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** my_swap.c
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return (0);
    for (int l = 0; str[l] != '\0'; l++)
        my_putchar(str[l]);
    return (0);
}