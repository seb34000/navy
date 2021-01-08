/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** error
*/

#include "navy.h"

int sa_ch(char a, char b)
{
    if (a == b)
        return (0);
    return (1);
}

int tcheck_size(char *lin, int test)
{
    int size = 0;

    if (((int)lin[2] > (int)lin[5]) || (int)lin[3] > (int)lin[6])
        return (84);
    if (test != (int)lin[0] - 48)
        return (84);
    if ((sa_ch(lin[2], lin[5]) == 0) && (sa_ch(lin[3], lin[6]) == 1)) {
        size = (int)lin[6] - (int)lin[3];
        size += 1;
    } else if ((sa_ch(lin[2], lin[5]) == 1) && (sa_ch(lin[3], lin[6]) == 0)) {
        size = (int)lin[5] - lin[2];
        size += 1;
    } else
        return (84);
    if (size != test || my_strlen(lin) < 5)
        return (84);
    return (0);
}

int tcheck_files(char *av)
{
    FILE *fp;
    char *buff = NULL;
    size_t len = 0;
    ssize_t read;
    int test = 2;

    fp = fopen(av, "r");
    if (fp == NULL)
        return (84);
    while ((read = getline(&buff, &len, fp)) != -1 && (test - 2) < 4) {
        if (tcheck_size(buff, test) == 84)
            return (84);
        test++;
    }
    if (test != 6)
        return (84);
    fclose(fp);
    return (0);
}

int testing(int ac, char **av)
{
    if (ac == 1 || ac > 3)
        return (84);
    if (ac == 2 && tcheck_files(av[1]) == 84)
        return (84);
    else if (ac == 3 && tcheck_files(av[2]) == 84)
        return (84);
    return (0);
}