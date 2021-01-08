/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** la base de mon print
*/

#include "../include/my.h"
#include "../include/my_printf.h"

void my_printf(char *str, ...)
{
    struct nbr_trf p;
    p.x = 0;
    p.format = malloc(sizeof(char) * 20);
    p.t = 0;
    va_start(p.ap, str);

    my_memset(p.format, 19, '\0');
    for (; str[p.t]; p.t++) {
        if (str[p.t] == '%' && str[p.t + 1] != '\0') {
            boucle_print(str, &p);
        } else
            my_putchar(str[p.t]);
    }
    va_end(p.ap);
}

void boucle_print(char *str, struct nbr_trf *p)
{
    p->t++;
    for (int r = 0; r < ARRAY_SIZE; r++) {
        if (my_strcmp (my_getn(str, p->t, 2), func[r].s) == 2) {
            func[r].ptr(p->ap, p);
            p->t += 1;
            return ;
        }
    }
    for (int r = 0; r < ARRAY_SIZE ; r++) {
        if (str[p->t] == '\0')
            return ;
        if (str[p->t] == func[r].c) {
            func[r].ptr(p->ap, p);
            return ;
        }
    }
    boucle_print2(str, p);
}

void boucle_print2(char *str, struct nbr_trf *p)
{
    if (str[p->t] != '\0') {
        p->format[p->x] = str[p->t];
        p->x++;
        boucle_print(str, p);
    }
}