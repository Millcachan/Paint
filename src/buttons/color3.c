/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color3
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void white(paint_t *paint)
{
    sfColor white = {255, 255, 255, 255};

    COLOR = white;
    if (paint->tool.primary) {
        paint->tool.primary_color = white;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, white);
    } else {
        paint->tool.secondary_color = white;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, white);
    }
}

void light_gray(paint_t *paint)
{
    sfColor light_gray = {195, 195, 195, 255};

    COLOR = light_gray;
    if (paint->tool.primary) {
        paint->tool.primary_color = light_gray;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, light_gray);
    } else {
        paint->tool.secondary_color = light_gray;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, light_gray);
    }
}

void brown(paint_t *paint)
{
    sfColor brown = {185, 122, 87, 255};

    COLOR = brown;
    if (paint->tool.primary) {
        paint->tool.primary_color = brown;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, brown);
    } else {
        paint->tool.secondary_color = brown;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, brown);
    }
}

void pink(paint_t *paint)
{
    sfColor pink = {255, 174, 201, 255};

    COLOR = pink;
    if (paint->tool.primary) {
        paint->tool.primary_color = pink;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, pink);
    } else {
        paint->tool.secondary_color = pink;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, pink);
    }
}

void gold(paint_t *paint)
{
    sfColor gold = {254, 200, 14, 255};

    COLOR = gold;
    if (paint->tool.primary) {
        paint->tool.primary_color = gold;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, gold);
    } else {
        paint->tool.secondary_color = gold;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, gold);
    }
}
