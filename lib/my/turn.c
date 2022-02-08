/*
** EPITECH PROJECT, 2020
** turn
** File description:
** turn
*/

#include <stdio.h>
#include "my.h"

void remove_(char *nb)
{
    int i = 0;

    if (nb[0] < '0' | nb[0] > '9')
        my_putstr("Error: invalid input (positive number expected)\n");
    while (nb[i]) {
        if (nb[i] == '\n')
            nb[i] = '\0';
        i++;
    }
}

static int bug(nb *go, char **av, char **map)
{
    char *line = NULL;
    size_t linea = 0;
    char *matche = NULL;
    size_t matchea = 0;

    if (getline(&line, &linea, stdin) <= -1)
        return (84);
    remove_(line);
    go->nbline = my_getnbr(line);
    if (check_intput(go, av, map) == 84)
        return (5);
    my_putstr("Matches: ");
    if (getline(&matche, &matchea, stdin) <= -1)
        return (84);
    remove_(matche);
    go->nbmatche = my_getnbr(matche);
    if (check_intput(go, av, map) == 84)
        return (5);
}

int your_turn(nb *go, char **av, char **map)
{
    int i = 0;
    go->nbline = 1;
    go->nbmatche = 1;

    if (go->turn == 0)
        my_putstr("\nYour turn:\n");
    my_putstr("Line: ");
    i = bug(go, av, map);
    if (i != 0)
        return (i);
    my_putstr("Player removed ");
    my_put_nbr(go->nbmatche);
    my_putstr(" match(es) from line ");
    my_put_nbr(go->nbline);
    my_putchar('\n');
    return (0);
}