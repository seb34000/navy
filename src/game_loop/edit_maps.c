/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"
#include "my.h"

char *nb_to_cord(int nb)
{
    char *cord = malloc(sizeof(char) * 3);

    cord[0] = '@';
    cord[1] = '0';
    cord[2] = '\0';
    while (nb > 9) {
        cord[0] += 1;
        nb -= 10;
    }
    while (nb > 0) {
        cord[1] += 1;
        nb -= 1;
    }
    return (cord);
}

int cord_to_nbr(char *str)
{
    int nb = ((str[0] - '@') * 10);

    nb += str[1] - '0';
    return (nb);
}

int chech_hit(int pos, game_t *game)
{
    char point = game->my_maps[(pos % 10) - 1][(pos / 10) - 1];
    int shot = 0;

    if (point == '2' || point == '3' || point == '4' || point == '5') {
        game->my_maps[(pos % 10) - 1][(pos / 10) - 1] = 'x';
        shot = 6;
    }
    if (point == '.') {
        game->my_maps[(pos % 10) - 1][(pos / 10) - 1] = 'o';
        shot = 7;
    }
    if (point == 'o' || point == 'x') {
        shot = 7;
    }
    return (shot);
}

void make_shot(int pos, game_t *game, char x)
{
    game->enemy_maps[(pos % 10) - 1][(pos / 10) - 1] = x;
}

void print_maps(game_t *game)
{
    my_printf("my positions:\n");
    display_maps(game->my_maps);
    my_printf("\nenemy’s positions:\n");
    display_maps(game->enemy_maps);
    my_printf("\n");
}