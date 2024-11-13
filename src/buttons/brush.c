/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** brush
*/

#include "my.h"
#include "paint.h"

void feur(paint_t *paint)
{
    if (paint)
        my_putstr("This button is not developped yet.\n", 1);
}

void brush(paint_t *paint)
{
    ACTION = BRUSH;
    SHAPE = 0;
}
