/*
** EPITECH PROJECT, 2020
** print
** File description:
** print
*/

#include "my.h"

static void mapper(int size, nb *go, char **map)
{
    while (go->y != size + 2) {
        map[go->y][go->u] = '*';
        go->u++;
        while (go->u < go->space) {
                map[go->y][go->u] = ' ';
                go->u++;
        }
        for (int k = 0; k != go->matche; k++, go->u++)
            map[go->y][go->u] = '|';
        for (int n = 0; n < go->space - 1; n++, go->u++)
            map[go->y][go->u] = ' ';
        map[go->y][go->u] = '*';
        go->u = 0;
        go->y++;
        go->matche += 2;
        go->space--;
    }
}

static void first_line(int size, nb *go, char **map)
{
    while (go->u != (size * 2) + 1) {
        map[go->y][go->u] = '*';
        go->u++;
    }
}

static void last_line(int size, nb *go, char **map)
{
    while (go->u != (size * 2) + 1) {
        map[go->y][go->u] = '*';
        go->u++;
    }
}

char **print_game_board(int size, nb *go)
{
    go->u = 0;
    go->y = 0;
    char **map;
    go->matche = 1;
    go->space = size;
    go->match = size * size;
    map = my_malloc(size);

    first_line(size, go, map);
    go->y++;
    go->u = 0;
    mapper(size, go, map);
    go->y--;
    go->u = 0;
    last_line(size, go, map);
    map[go->y][go->u] = '\0';
    print_map(map, size);
    return (map);
}