/*
** EPITECH PROJECT, 2021
** check_neighbours_one.c
** File description:
** check_neighbours_one
*/

#include "include/helper.h"
#include "include/my.h"

int check_neighbour_top_left_corner(char **map, int i, int j)
{
    if ((i - 1) < 0) {
        return (0);
    }
    if ((j - 1) < 0) {
        return (0);
    }
    if (map[i - 1][j - 1] == '.') {
        return (0);
    } else if (map[i - 1][j - 1] == 'X'){
        return (1);
    }
}

int check_neighbour_top(char **map, int i, int j)
{
    if ((i - 1) < 0) {
        return (0);
    }
    if (map[i - 1][j] == '.') {
        return (0);
    } else if (map[i - 1][j] == 'X'){
        return (1);
    }
}

int check_neighbour_top_right_corner(char **map, int i, int j, int cols)
{
    if ((i - 1) < 0) {
        return (0);
    }
    if ((j + 1) < 0 || j + 1 >= cols) {
        return (0);
    }
    if (map[i - 1][j + 1] == '.') {
        return (0);
    } else if (map[i - 1][j + 1] == 'X'){
        return (1);
    }
}

int check_neighbour_right(char **map, int i, int j, int cols)
{
    if (j + 1 >= cols) 
        return (0);
    if ((j + 1) < 0) {
        return (0);
    }
    if (map[i][j + 1] == '.') {
        return (0);
    } else if (map[i][j + 1] == 'X'){
        return (1);
    }
}

int check_neighbour_left(char **map, int i, int j)
{
    if ((j - 1) < 0) {
        return (0);
    }
    if (map[i][j - 1] == '.') {
        return (0);
    } else if (map[i][j - 1] == 'X'){
        return (1);
    }
}