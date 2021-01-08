/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"
#include "my.h"

int main(int ac, char **av)
{
    game_t game;
    int finich = 0;

    if (ac == 1)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        get_man();
        return (0);
    }
    if (testing(ac, av) == 84)
        return (84);
    if (testing(ac, av) == 1)
        return (0);
    game = set_game(ac, av);
    if (game.error == 84)
        return (84);
    finich = game_loop(&game);
    return (finich);
}

game_t set_game(int ac, char **av)
{
    game_t game;

    game.num_playeur = (ac - 1);
    if (game.num_playeur == 1) {
        game = first_conextion_p1(game);
    }
    if (game.num_playeur == 2) {
        game.ennemi_pid = my_getnbr(av[1]);
        game = first_conextion_p2(game);
    }
    game.my_maps = set_boat(av[ac - 1], set_maps());
    game.enemy_maps = set_maps();
    return (game);
}