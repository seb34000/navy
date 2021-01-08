/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int t = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(dest) + 1));

    for (t = 0;dest[t] != '\0'; t++)
        str[t] = dest[t];
    for (int r = 0; src[r] != '\0'; t++, r++)
        str[t] = src[r];
    str[t] = '\0';
    return (str);
}