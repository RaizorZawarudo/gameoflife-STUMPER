/*
** EPITECH PROJECT, 2021
** check_neighbours_two.c
** File description:
** check_neighbours_two
*/

#include "include/helper.h"
#include "include/my.h"

int check_neighbour_bottom_left_corner(char **map, int i, int j, int rows)
{
    if ((i + 1) < 0 || i + 1 >= rows) {
        return (0);
    }
    if ((j - 1) < 0) {
        return (0);
    }
    if (map[i + 1][j - 1] == '.') {
        return (0);
    } else if (map[i + 1][j - 1] == 'X'){
        return (1);
    }
}

int check_neighbour_bottom_right_corner(char **map, int i, int j, char *buffer)
{
    int rows = getrows(buffer);
    int cols = getcols(buffer);

    if ((i + 1) < 0 || i + 1 >= rows) {
        return (0);
    }
    if ((j + 1) >= cols) {
        return (0);
    }
    if (map[i + 1][j + 1] == '.') {
        return (0);
    } else if (map[i + 1][j + 1] == 'X'){
        return (1);
    }
}

int check_neighbour_bottom(char **map, int i, int j, int rows)
{
    if (i + 1 >= rows) {
        return (0);
    }
    if (map[i + 1][j] == '.') {
        return (0);
    } else if (map[i + 1][j] == 'X'){
        return (1);
    }
}