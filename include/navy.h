/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdbool.h>

#define COL_X_RED	    "\033[31m"
#define BG_BLUE	        "\033[44m"
#define FG_BOLD	        "\033[1m"
#define COL_2_GREEN	    "\033[32m"
#define COL_3_YELLOW	"\033[33m"
#define COL_4_BLUE	    "\033[34m"
#define COL_5_PURPLE	"\033[35m"
#define COL_O_BLUE	    "\033[36m"
#define COL_DEF	        "\033[0m"
#define SUPRIME         "\b"

typedef struct signal_s
{
    bool in_com;
    int nb_signal;
    pid_t ennemi_pid;
} signal_t;

typedef struct game_s
{
    int num_playeur;
    char **my_maps;
    char **enemy_maps;
    pid_t ennemi_pid;
    int error;
    int game_over;
} game_t;

// main //
game_t set_game(int ac, char **av);

// comunication //
game_t first_conextion_p1(game_t game);
game_t first_conextion_p2(game_t game);
void send_signal(char *str, pid_t id);
void handler(int sig, siginfo_t *info, void *context);
int catch_signal(void);

// maps //
char **set_maps(void);
char **set_boat(char *name_file, char **maps);
char **set_boat_position(char *line, char **maps);
void display_maps(char **maps);

// error //
int testing(int ac, char **av);
int sa_ch(char a, char b);
int tcheck_size(char *line, int test);
int tcheck_files(char *av);
void get_man(void);

// game_loop //
int game_loop(game_t *game);
void shot(game_t *game);
void take_shot(game_t *game);
int check_operation(char *str);

// edit_maps //
char *nb_to_cord(int nb);
int cord_to_nbr(char *str);
int chech_hit(int pos, game_t *game);
void make_shot(int pos, game_t *game, char x);
void print_maps(game_t *game);

// end game //
int im_alive(game_t *game);
int i_lose(game_t *game);
int i_win(game_t *game);