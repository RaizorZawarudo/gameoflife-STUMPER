/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** display words of an array
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *src);

char *my_strcpy(char *dest, char const *src);

int count(char *dest)
{
    int i = 0;
    int count1 = 0;

    for (int i = 0; i < my_strlen(dest) + 1; i++) {
        if ('0' > dest[i] || dest[i] > 'z' ||
            '9' < dest[i] && dest[i] < 'A' ||
            'Z' < dest[i] && dest[i] < 'a') {
            count1++;
        }
    }
    return (count1);
}

char **words(char *dest, char **arr)
{
    int letters = 0;
    int words = 0;

    for (int i = 0; i < my_strlen(dest) + 1; i++) {
        if ('0' <= dest[i] && dest[i] <= '9' ||
            'A' <= dest[i] && dest[i] <= 'Z' ||
            'a' <= dest[i] && dest[i] <= 'z') {
            letters++;
        } else {
            arr[words] = malloc(sizeof(char) * (letters + 1));
            words++;
            letters = 0;
        }
    }
    return (arr);
}

char **set_array(char *dest, char **arr)
{
    int i = 0;
    int k = 0;
    int count1 = 0;

    for (; i < my_strlen(dest); i++) {
        while ('0' <= dest[i] && dest[i] <= '9' ||
            'A' <= dest[i] && dest[i] <= 'Z' ||
            'a' <= dest[i] && dest[i] <= 'z') {
            arr[count1][k] = dest[i];
            k++;
            i++;
        }
        arr[count1][k] = '\0';
        count1++;
        k = 0;
    }
    arr[count1] = NULL;
    return (arr);
}

char **my_str_to_word_array(char const *str)
{
    int len = my_strlen(str);
    int count1 = 0;
    char *dest = malloc (sizeof(char) * (len + 1));
    char **arr = 0;

    dest = my_strcpy(dest, str);
    count1 = count(dest);
    arr = malloc(sizeof(char *) * (count1 + 1));
    words(dest, arr);
    arr = set_array(dest, arr);
    arr[count1] = NULL;
    free(dest);
    return (arr);
}
