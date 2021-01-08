/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"
#include "my.h"

int im_alive(game_t *game)
{
    int life = 0;
    char **maps = game->my_maps;

    for (int t = 0; t < 8; t++) {
        for (int r = 0; r < 8; r++) {
            life += maps[t][r] == '2' ? 1 : 0;
            life += maps[t][r] == '3' ? 1 : 0;
            life += maps[t][r] == '4' ? 1 : 0;
            life += maps[t][r] == '5' ? 1 : 0;
        }
    }
    if (life != 0)
        return (1);
    return (0);
}

int i_lose(game_t *game)
{
    print_maps(game);
    my_printf("Enemy won\n\n");
    return (1);
}

int i_win(game_t *game)
{
    print_maps(game);
    my_printf("I won\n\n");
    return (0);
}