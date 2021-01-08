/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"

void send_signal(char *str, pid_t id)
{
    int n_signal = 0;

    n_signal = (10 * (str[0] - 64));
    n_signal += (str[1] - 48);
    for (int t = 0; t < n_signal; t++) {
        kill(id, 30);
        usleep(100);
    }
    kill(id, 31);
}