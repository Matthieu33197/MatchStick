/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "my.h"

char **mem_alloc_2d_array(int nb_row, int nb_cols)
{
    int i = 0;
    char **new_str = malloc(sizeof(char *) * nb_row + 1);

    while (i != nb_row) {
        new_str[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    return (new_str);
}

char **my_malloc(int size)
{
    int nb_cols = 0;
    int nb_line = 0;

    nb_cols = (size * 2) + 3;
    nb_line = size + 2;
    return (mem_alloc_2d_array(nb_line, nb_cols));
}

void print_map(char **map, int size)
{
    int i = 0;
    while (i != size + 2) {
        my_putstr(map[i]);
        my_putchar('\n');
        i++;
    }
}

void update_map(nb *go, char **map, int size)
{
    int i = my_strlen(map[go->nbline]);
    char o;

    while (map[go->nbline][i] != '|') {
        i--;
    }
    while (go->nbmatche > 0 && map[go->nbline][i] != '*') {
        map[go->nbline][i] = ' ';
        i--;
        go->nbmatche--;
    }
    print_map(map, size);
}