/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** my_strncpy.c
*/

void slide(char *str)
{
    int t = 0;

    str[t] = '0';
    for (; str[t] != '\0'; t++)
        str[t] = str[t + 1];
    str[t] = '\0';
}