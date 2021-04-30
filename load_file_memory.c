/*
** EPITECH PROJECT, 2021
** load_file_memory.c
** File description:
** load_file_memory
*/

#include "include/helper.h"
#include "include/my.h"

char *load_file_in_mem(char const *filepath)
{
    int filedescriptor = 0;
    int size;
    struct stat stats;
    char *buffer;

    filedescriptor = open(filepath, O_RDONLY);
    if (filedescriptor == -1) {
        my_putstr("No such file");
        exit (FAIL_RETURN);
    }
    stat(filepath, &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    read(filedescriptor, buffer, size);
    close(filedescriptor);
    return (buffer);
}

char **mem_alloc_2d_array(char *buffer, int map_rows, int map_cols)
{
    char **map = malloc(sizeof(char *) * (map_rows + 1));
    for (int i = 0; i < map_rows; i++) {
        map[i] = malloc(sizeof(char) * (map_cols + 1));
        map[i][map_cols] = '\0';
    }
    return map;
}