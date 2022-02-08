/*
** EPITECH PROJECT, 2020
** print game board
** File description:
** print game board
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib/my/my.h"

static int norme(nb *go, char **map, int i)
{
    while (i < 1) {
        i = check_line_bot(go, map);
            go->nbline--;
    }
    return (i);
}

static void bot(nb *go, char **map, int size, int match)
{
    go->nbline = size + 1;
    int i = 0;
    int j = 0;

    i = norme(go, map, i);
    while (j != 1) {
        if (i <= match) {
            go->nbline++;
            my_putstr("\nAI's turn...\nAI removed ");
            my_put_nbr(i);
            my_putstr(" match(es) from line ");
            my_put_nbr(go->nbline);
            my_putchar('\n');
            j = 1;
        } else
            i--;
    }
    go->nbmatche = i;
}

static int games(char **av)
{
    nb *go = malloc(sizeof(nb));
    int i = 0;
    char **map = print_game_board(my_getnbr(av[1]), go);

    while (go->match > 0) {
        go->turn = 0;
        i = your_turn(go, av, map);
        if (i == 84)
            return (0);
        else if (i == 5) {
            while (i == 5) {
                go->turn = 1;
                i = your_turn(go, av, map);
            }
            if (i == 84)
                return (0);
        }
        if (i == 0) {
            update_map(go, map, my_getnbr(av[1]));
            if (lose_player(map) == 2)
                return (2);
            bot(go, map, my_getnbr(av[1]), my_getnbr(av[2]));
            update_map(go, map, my_getnbr(av[1]));
            if (lose_bot(map) == 1)
                return (1);
        }
    }
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 3) {
        i = games(av);
        if (i == 0)
            return (0);
        else if (i == 1)
            return (1);
        else
            return (2);
    }
    else
        return (84);
}
