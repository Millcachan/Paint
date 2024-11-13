/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

char *my_strdup(char *src)
{
    return (!src) ? NULL :
    my_strcpy(malloc((size_t)(my_strlen(src) + 1)), src);
}
