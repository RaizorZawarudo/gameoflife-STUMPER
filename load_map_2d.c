/*
** EPITECH PROJECT, 2021
** load_map_2d.c
** File description:
** load_map_2d
*/

#include "include/helper.h"
#include "include/my.h"

char **map_gen(char *buffer, int map_rows, int map_cols)
{
    int j = 0;
    int position = 0;

    char **map = malloc(sizeof(char *) * (map_rows + 1));
    for (int i = 0; i < map_rows; i++) {
        j = 0;
        map[i] = malloc(sizeof(char) * (map_cols + 2));
        for (; j < map_cols; j++) {
            map[i][j] = buffer[position];
            position++;
        }
        map[i][j + 1] = '\0';
        position++;
    }
    return map;
}