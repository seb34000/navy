/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** fait la convertion dec vers oct
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void my_showstr_octal(char *str)
{
    for (int t = 0; str[t] != '\0'; t++) {
        if (str[t] < 33 || str[t] == 127) {
            my_putchar('/');
            n_to_oct(str[t]);
        } else
            my_putchar(str[t]);
    }
}

void n_to_oct(long long dec)
{
    char *sto = malloc(sizeof(char) * 22);
    int n = 21;
    int cm = 0;
    long long hex = my_puisance_l(8, n);

    sto[21] = '\0';
    my_memset(sto, 21, '0');
    if (dec < 0)
        dec = 4294967295 + dec;
    for (int t = 0; dec > 0 ; n--, t++) {
        hex = my_puisance_l(8, n);
        if (hex <= dec) {
            cm = cm_to_int(dec, hex);
            dec -= (cm * hex);
            sto[t] = c_to_hec(cm);
        }
    }
    supr_to_oct(sto);
}

void supr_to_oct(char *str)
{
    int t = 0;

    for (; str[0] == '0';)
        slide(str);
    t = my_strlen(str);
    t = 3 - t;
    for (;t != 0; t--)
        my_putchar('0');
    my_printf("%s", str);
}