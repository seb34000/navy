/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "navy.h"
#include "my_printf.h"
#include "my.h"

char **set_maps(void)
{
    char **maps = malloc(sizeof(char *) * 9);

    maps[8] = NULL;
    for (int t = 0; t != 8; t++) {
        maps[t] = malloc(sizeof(char) * 9);
        maps[t][8] = '\0';
        for (int r = 0; r != 8; r++) {
            maps[t][r] = '.';
        }
    }
    return (maps);
}

char **set_boat(char *name_file, char **maps)
{
    FILE *fd;
    size_t len = 0;
    ssize_t read;
    char *line;
    fd = fopen(name_file, "r");
    if (fd == NULL) {
        my_printf("error\n");
        return (maps);
    }
    while ((read = getline(&line, &len, fd)) != -1) {
        maps = set_boat_position(line, maps);
    }
    my_printf("\n");
    fclose(fd);
    return (maps);
}

char **set_boat_position(char *linne, char **maps)
{
    char *line = my_strcpy(linne, "");
    int len = line[0];

    if (line[2] != line[5]) {
        while (line[2] != (line[5] + 1)) {
            maps[(line[3] - 48) - 1][(line[2] - 64) - 1] = len;
            line[2] = line[2] + 1;
        }
    }
    if (line[3] != line[6]) {
        while (line[3] != (line[6] + 1)) {
            maps[(line[3] - 48) - 1][(line[2] - 64) - 1] = len;
            line[3] = line[3] + 1;
        }
    }
    return (maps);
}

void display_maps(char **maps)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int t = 0; maps[t] != NULL; t++) {
        my_printf("%d|", (t + 1));
        for (int r = 0; maps[t][r + 1] != '\0'; r++) {
            my_printf("%c ", maps[t][r]);
        }
        my_printf("%c\n", maps[t][7]);
    }
}