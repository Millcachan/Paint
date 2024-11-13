/*
** EPITECH PROJECT, 2024
** my_freetab.c
** File description:
** my_freetab
*/

#include "../../include/my.h"

void my_freetab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        if (tab[i])
            free(tab[i]);
    free(tab);
}
