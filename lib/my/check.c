/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

int check_line(nb *go, char **map)
{
    int i = 0;
    int j = 0;

    while (i < my_strlen(map[go->nbline])) {
        if (map[go->nbline][i] == '|')
            j++;
        i++;
    }
    if (go->nbmatche > j) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    } else
        return (0);
}

static int error(nb *go, char **av, char **map, int i)
{
    if (go->nbline > my_getnbr(av[1])) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    } else if (go->nbmatche > my_getnbr(av[2])) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(my_getnbr(av[2]));
        my_putstr(" matches per turn\n");
        return (84);
    } else {
        i = check_line(go, map);
        if (i == 1)
            return (84);
        else
            return (0);
    }
}

int check_intput(nb *go, char **av, char **map)
{
    int i = 0;

    if (go->nbline == 0) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    } else if (go->nbmatche == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    } else {
        return (error(go, av, map, i));
    }
}

int check_line_bot(nb *go, char **map)
{
    int i = 0;
    int j = 0;

    while (i < my_strlen(map[go->nbline])) {
        if (map[go->nbline][i] == '|')
            j++;
        i++;
    }
    if (j != 0)
        return (j);
    else
        return (0);
}