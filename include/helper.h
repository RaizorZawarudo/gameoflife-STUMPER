/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

typedef struct mushroom {
    int neighbours;
    int lifestate;
    struct mushroom *next;
} mushroom;

int check_args(char **av);

char **mem_alloc_2d_array(char *buffer, int nb_rows, int nb_cols);

char *load_file_in_mem(char const *filepath);

char **map_gen(char *filepath, int map_rows, int map_cols);

int gameoflife_init(char **av);

int getcols(char *buffer);

int getrows(char *buffer);

int check_neighbour_left(char **map, int i, int j);

int check_neighbour_top_left_corner(char **map, int i, int j);

int check_neighbour_top(char **map, int i, int j);

int check_neighbour_top_right_corner(char **map, int i, int j, int cols);

int check_neighbour_right(char **map, int i, int j, int cols);

int check_neighbour_bottom_right_corner(char **map, int i, int j, char *buffer);

int check_neighbour_bottom(char **map, int i, int j, int rows);

int check_neighbour_bottom_left_corner(char **map, int i, int j, int rows);

#endif /* !HELPER_H_ */
