/*
** EPITECH PROJECT, 2024
** Minishell
** File description:
** my_strcomb
*/

#include "../../include/my.h"

char *my_strcomb(char *s1, char *s2)
{
    int index = 0;
    char *string = malloc((size_t)(my_strlen(s1) + my_strlen(s2) + 1));

    while (s1[index]) {
        string[index] = s1[index];
        index++;
    }
    string[index] = '/';
    index++;
    for (int i = 0; s2[i]; i++) {
        string[index] = s2[i];
        index++;
    }
    return string;
}
