/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** convertion de base
*/

#include "../include/my.h"
#include "../include/my_printf.h"

char *my_dec_to_hex(long long dec)
{
    char *sto = malloc(sizeof(char) * 16);
    int n = 15;
    int cm = 0;
    long long hex = my_puisance_l(16, n);

    sto[15] = '\0';
    my_memset(sto, 15, '0');
    if (dec < 0) {
        dec = 4294967295 + dec;
    }
    for (int t = 0; dec > 0 ; n--, t++) {
        hex = my_puisance_l(16, n);
        if (hex <= dec) {
            cm = cm_to_int(dec, hex);
            dec -= (cm * hex);
            sto[t] = c_to_hec(cm);
        }
    }
    return (suprime_zero(sto));
}

char *my_dec_to_hex_maj(long long dec)
{
    char *sto = malloc(sizeof(char) * 16);
    int n = 15;
    int cm = 0;
    long long hex = my_puisance_l(16, n);

    sto[15] = '\0';
    my_memset(sto, 15, '0');
    if (dec < 0) {
        dec = 4294967295 + dec;
    }
    for (int t = 0; dec > 0 ; n--, t++) {
        hex = my_puisance_l(16, n);
        if (hex <= dec) {
            cm = cm_to_int(dec, hex);
            dec -= (cm * hex);
            sto[t] = c_to_hec_maj(cm);
        }
    }
    return (suprime_zero(sto));
}

char *my_dec_to_oct(long long dec)
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
    return (suprime_zero(sto));
}

char *my_dec_to_bin(long long dec)
{
    char *sto = malloc(sizeof(char) * 33);
    int n = 31;
    int cm = 0;
    long long hex = my_puisance_l(2, n);

    sto[32] = '\0';
    my_memset(sto, 31, '0');
    if (dec < 0)
        dec = 4294967295 + dec;
    for (int t = 0; dec > 0 ; n--, t++) {
        hex = my_puisance_l(2, n);
        if (hex <= dec) {
            cm = cm_to_int(dec, hex);
            dec -= (cm * hex);
            sto[t] = c_to_hec(cm);
        }
    }
    return (suprime_zero(sto));
}