/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int len_dest = my_strlen(dest);
    int len_src;

    for (len_src = 0; src[len_src]; len_src++)
        dest[len_dest + len_src] = src[len_src];
    dest[len_dest + len_src] = '\0';
    return dest;
}
