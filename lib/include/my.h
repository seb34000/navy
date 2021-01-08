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

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_put_float_nbr(double nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
void my_memset(char *str, int size, char c);
char *my_put_nbr_char(int nb);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_char_isnum(char n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
void my_showstr(char const *str);
char *my_dectohex(char c, char *sto);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
char *zero_bistro(char *str, int size);
void my_memset(char *str, int size, char c);
char *my_strdup(char *src);
char *my_getn(char *str, int p, int nbchar);
long long my_puisance_l(int a, int b);
void slide(char *str);
char **my_sort_in_ascii(char **str);
char **my_str_to_word_array(char const *str);
char **my_add_str_to_double(char *str, char **dlbe); 
// ajoute une chaibne de caratère a la fin d'un double tableau //