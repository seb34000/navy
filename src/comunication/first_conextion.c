/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"

static signal_t get_signal;

void first_handler(int sig, siginfo_t *info, void *context)
{
    (void) sig;
    (void) *context;
    get_signal.ennemi_pid = info->si_pid;
}

game_t first_conextion_p1(game_t game)
{
    pid_t my_id = getpid();
    struct sigaction sig;

    sig.sa_sigaction = first_handler;
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(30, &sig, NULL) < 0) {
        game.error = 84;
        return (game);
    }
    my_printf("my_pid: %d\n", my_id);
    my_printf("waiting for enemy connection...\n");
    pause();
    if (get_signal.ennemi_pid != 0) {
        game.ennemi_pid = get_signal.ennemi_pid;
        my_printf("\nenemy connected\n");
        send_signal("@5", game.ennemi_pid);
    } else {
        my_printf("\nerror connection\n");
        game.error = 84;
    }
    return (game);
}

game_t first_conextion_p2(game_t game)
{
    pid_t my_id = getpid();
    int signal = 0;

    my_printf("my_pid: %d\n", my_id);
    kill(game.ennemi_pid, 30);
    signal = catch_signal();
    if (signal == 5) {
        my_printf("successfully connected\n");
    } else {
        my_printf("\nerror connection\n");
        game.error = 84;
    }
    return (game);
}