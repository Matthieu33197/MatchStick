/*
** EPITECH PROJECT, 2019
** my
** File description:
** all my
*/

#ifndef __MY_H__
#define __MY_H__

#include <stddef.h>
#include <stdlib.h>

typedef struct nb_struct
{
    int turn;
    int u;
    int y;
    int space;
    int matche;
    int match;
    int nbmatche;
    int nbline;
} nb;

int my_getnbr(char *nbr);
int my_strlen(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
void my_put_nbr(int nb);
char **print_game_board(int size, nb *go);
int check_line(nb *go, char **map);
int check_intput(nb *go, char **av, char **map);
int check_line_bot(nb *go, char **map);
int lose_player(char **map);
int lose_bot(char **map);
char **mem_alloc_2d_array(int nb_row, int nb_cols);
char **my_malloc(int size);
void print_map(char **map, int size);
void update_map(nb *go, char **map, int size);
int your_turn(nb *go, char **av, char **map);
void remove_(char *nb);

#endif
