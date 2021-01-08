/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** my_revstr.c
*/

int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);

#include <stdio.h>

char *my_revstr(char *str)
{
    char sto[my_strlen(str)];
    int t = 0;
    int pt = 0;
    int tstr;

    for (t = 0; str[t] != '\0'; t++)
        tstr = t;
    for (; t != 0; t--, pt++)
        sto[pt] = str[t - 1];
    for (; (tstr+1) != t; t++)
        str[t] = sto[t];
    str[t] = '\0';
    return (str);
}