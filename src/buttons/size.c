/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** size
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void one_pixel(paint_t *paint)
{
    paint->tool.size = 1;
}

void three_pixel(paint_t *paint)
{
    paint->tool.size = 3;
}

void five_pixel(paint_t *paint)
{
    paint->tool.size = 5;
}

void eight_pixel(paint_t *paint)
{
    paint->tool.size = 8;
}
