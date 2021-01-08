/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"
#include "my.h"

int game_loop(game_t *game)
{
    print_maps(game);
    while (game->num_playeur == 1) {
        shot(game);
        if (game->game_over == 1)
            return (i_win(game));
        take_shot(game);
        if (game->game_over == 1)
            return (i_lose(game));
        print_maps(game);
    }
    while (game->num_playeur == 2) {
        take_shot(game);
        if (game->game_over == 1)
            return (i_lose(game));
        shot(game);
        if (game->game_over == 1)
            return (i_win(game));
        print_maps(game);
    }
    return (84);
}

void shot(game_t *game)
{
    char *line = NULL;
    size_t len = 0;
    int signal = 0;

    my_printf("attack: ");
    getline(&line, &len, stdin);
    while (check_operation(line) != 0) {
        my_printf("wrong position\nattack: ");
        getline(&line, &len, stdin);
    }
    send_signal(line, game->ennemi_pid);
    signal = catch_signal();
    if (signal == 6 || signal == 5) {
        my_printf("%c%c: hit\n\n", line[0], line[1]);
        make_shot(cord_to_nbr(line), game, 'x');
        game->game_over = signal == 5 ? 1 : 0;
    } else if (signal == 7) {
        my_printf("%c%c: missed\n\n", line[0], line[1]);
        make_shot(cord_to_nbr(line), game, 'o');
    }
}

void take_shot(game_t *game)
{
    int shot;
    int chech;
    char *line;

    my_printf("waiting for enemy's attack...\n");
    shot = catch_signal();
    chech = chech_hit(shot, game);
    line = nb_to_cord(shot);
    if (im_alive(game) == 0) {
        my_printf("%c%c: hit\n\n", line[0], line[1]);
        send_signal("@5", game->ennemi_pid);
        game->game_over = 1;
        return ;
    } else if (chech == 6) {
        my_printf("%c%c: hit\n\n", line[0], line[1]);
        send_signal("@6", game->ennemi_pid);
    } else if (chech == 7) {
        my_printf("%c%c: missed\n\n", line[0], line[1]);
        send_signal("@7", game->ennemi_pid);
    }
}

int check_operation(char *str)
{
    if (my_strlen(str) != 3)
        return (84);
    if (str[0] < 'A' || str[0] > 'H')
        return (84);
    if (str[1] < '1' || str[1] > '8')
        return (84);
    if (str[2] != '\n')
        return (84);
    return (0);
}