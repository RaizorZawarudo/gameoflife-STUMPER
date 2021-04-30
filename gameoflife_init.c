/*
** EPITECH PROJECT, 2021
** gameoflife_init.c
** File description:
** gameoflife_init
*/

#include "include/helper.h"
#include "include/my.h"

int getcols(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        count++;
    }
    return (count);
}

int getrows(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            count++;
        }
    }
    return (count);
}

char check_life(char **map, int i, int j, char *buffer)
{
    int neighbour_amount = 0;
    int rows = getrows(buffer);
    int cols = getcols(buffer);

    neighbour_amount += check_neighbour_left(map, i, j);
    neighbour_amount += check_neighbour_top_left_corner(map, i, j);
    neighbour_amount += check_neighbour_top(map, i, j);
    neighbour_amount += check_neighbour_top_right_corner(map, i, j, cols);
    neighbour_amount += check_neighbour_right(map, i, j, cols);
    neighbour_amount += check_neighbour_bottom_right_corner(map, i, j, buffer);
    neighbour_amount += check_neighbour_bottom(map, i, j, rows);
    neighbour_amount += check_neighbour_bottom_left_corner(map, i, j, rows);
    if (neighbour_amount == 0 || neighbour_amount == 1 ||  neighbour_amount >= 4 && neighbour_amount != 3) {
        neighbour_amount = 0;
        return ('.');
    } else if (neighbour_amount == 2 && map[i][j] == '.') {
        return ('.');
    } else {
        neighbour_amount = 0;
        return ('X');
    }
}

char **gameoflife_loop(char **map, int rows, int cols, char *buffer)
{
    char **itermap = mem_alloc_2d_array(buffer, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            itermap[i][j] = check_life(map, i, j, buffer);
        }
    }
    return (itermap);
}

int gameoflife_init(char **av)
{
    char *buffer = load_file_in_mem(av[1]);
    int rows = getrows(buffer);
    int cols = getcols(buffer);
    char **map = map_gen(buffer, rows, cols);

    for (int i = 0; i < my_getnbr(av[2]); i++) {
        map = gameoflife_loop(map, rows, cols, buffer);
    }
    for (int i = 0; i < rows; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (SUCCESS_RETURN);
}