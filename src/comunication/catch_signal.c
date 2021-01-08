/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"

static signal_t get_signal;

void handler(int sig, siginfo_t *info, void *context)
{
    (void) *info;
    (void) *context;
    if (sig == 30)
        get_signal.nb_signal += 1;
    if (sig == 31)
        get_signal.in_com = false;
}

int catch_signal(void)
{
    struct sigaction sig;

    get_signal.in_com = true;
    get_signal.nb_signal = 0;
    sig.sa_sigaction = handler;
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(30, &sig, NULL) < 0)
        return (1);
    if (sigaction(31, &sig, NULL) < 0)
        return (1);
    while (get_signal.in_com == true) {
        pause();
    }
    return (get_signal.nb_signal);
}