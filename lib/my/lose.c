/*
** EPITECH PROJECT, 2020
** lose
** File description:
** lose
*/

#include "my.h"

int lose_player(char **map)
{
    int i = 0;
    int j = 0;
    int n = 0;
    int l = 0;

    while (map[j] != NULL) {
        while (map[j][i] != '\n' && map[j][i] != '\0') {
            ((map[j][i] == '|')?(l = 1):(0));
            i++;
        }
        n = i;
        i = 0;
        j++;
    }
    if (l != 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    return (0);
}

int lose_bot(char **map)
{
    int i = 0;
    int j = 0;
    int n = 0;
    int l = 0;

    while (map[j] != NULL) {
        while (map[j][i] != '\n' && map[j][i] != '\0') {
            ((map[j][i] == '|')?(l = 1):(0));
            i++;
        }
        n = i;
        i = 0;
        j++;
    }
    if (l != 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}