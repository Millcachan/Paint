/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** reset.c
*/

#include "my.h"
#include "paint.h"

void reset(paint_t *paint)
{
    for (int i = 0; i < (1152 * 648 * 4); i++)
        paint->canva.pixels[i] = 255;
}
