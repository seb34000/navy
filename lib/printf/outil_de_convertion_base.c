/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** fait plusieur convertion de base
*/

#include "../include/my.h"
#include "../include/my_printf.h"

char c_to_hec_maj(int dec)
{
    char c;

    if (dec < 10) {
        c = '0';
        c += dec;
    } else {
        dec -= 10;
        c = 'A';
        c += dec;
    }
    return (c);
}

char c_to_hec(int dec)
{
    char c;

    if (dec < 10) {
        c = '0';
        c += dec;
    } else {
        dec -= 10;
        c = 'a';
        c += dec;
    }
    return (c);
}

int cm_to_int(long long dec, long long hex)
{
    int t = 0;

    for (;dec >= 0; t++) {
        dec -= hex;
    }
    return (t-1);
}

char *suprime_zero(char *str)
{
    for (; str[0] == '0';)
        slide(str);
    return (str);
}

long long my_puisance_l(int a, int b)
{
    long long sto_a = a;
    long long zero = 1;

    if (b == 0)
        return (zero);
    for (; b > 1; b--)
        sto_a = (sto_a * a);
    return (sto_a);
}