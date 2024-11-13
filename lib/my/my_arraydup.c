/*
** EPITECH PROJECT, 2024
** my_arraydup.c
** File description:
** my_arraydup
*/

#include "../../include/my.h"

char **my_arraydup(char **arr)
{
    int count = 0;
    char **new_arr;

    while (arr[count] != NULL)
        count++;
    new_arr = malloc((size_t)((count + 1) * (int)sizeof(char *)));
    for (int i = 0; i < count; i++)
        new_arr[i] = my_strdup(arr[i]);
    new_arr[count] = NULL;
    return new_arr;
}
