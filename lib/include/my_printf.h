/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#define ARRAY_SIZE 13

struct nbr_trf
{
    int x;
    char *format;
    va_list ap;
    int t;
};
typedef struct array_s
{
    char c;
    char *s;
    void (*ptr)(va_list, struct nbr_trf *p);
} array_t;

void my_printf(char *str, ...);
void boucle_print(char *str, struct nbr_trf *p);
void boucle_print2(char *str, struct nbr_trf *p);
void my_put_padress(void const *p);
void my_put_long_long_nbr(long long nb);
int my_put_nbr_unsigned(unsigned nb);


// flags d-s-c-f-ld
void is_a_nbr(va_list ap, struct nbr_trf *p);
void is_a_string(va_list ap, struct nbr_trf *p);
void is_a_char(va_list ap, struct nbr_trf *p);
void is_a_float(va_list ap, struct nbr_trf *p);

// flags S-b-p-crct
void is_a_showstr_octal(va_list ap, struct nbr_trf *p);
void is_a_unsigned_nbr(va_list ap, struct nbr_trf *p);
void is_a_pointeur(va_list ap, struct nbr_trf *p);
void is_a_pourcent(va_list ap, struct nbr_trf *p);

// flags_convertion_base
void is_a_dec_to_hex(va_list ap, struct nbr_trf *p);
void is_a_dec_to_hex_maj(va_list ap, struct nbr_trf *p);
void is_a_dec_to_oct(va_list ap, struct nbr_trf *p);
void is_a_dec_to_bin(va_list ap, struct nbr_trf *p);


char *my_dec_to_str(long long hex, long long dec, char *sto);
void format_nbr(char *str, char *form);


// showstr_octal
void my_showstr_octal(char *str);
void n_to_oct(long long dec);
void supr_to_oct(char *str);

// convertion de base
char *my_dec_to_hex(long long dec);
char *my_dec_to_hex_maj(long long dec);
char *my_dec_to_oct(long long dec);
char *my_dec_to_bin(long long dec);

// outil de convertion de base
char c_to_hec_maj(int dec);
char c_to_hec(int dec);
int cm_to_int(long long dec, long long hex);
char *suprime_zero(char *str);
// format nbr
void format_nbr_plus(char *str, char *form);
void format_nbr_moins(char *str, char *form);
void format_nbr_point(char *str, char *form);
// format str
void format_str(char *str, char *form);
void format_str_plus(char *str, char *form);
void format_str_moins(char *str, char *form);
void format_str_point(char *str, char *form);

static array_t func[] = {
    {'c', "", is_a_char},
    {'s', "", is_a_string},
    {'i', "", is_a_nbr},
    {'d', "", is_a_nbr},
    {'u', "", is_a_unsigned_nbr},
    {'f', "lf", is_a_float},
    {'x', "lx", is_a_dec_to_hex},
    {'X', "", is_a_dec_to_hex_maj},
    {'o', "", is_a_dec_to_oct},
    {'b', "", is_a_dec_to_bin},
    {'S', "", is_a_showstr_octal},
    {'p', "", is_a_pointeur},
    {'%', "", is_a_pourcent}
};