/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color1
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void black(paint_t *paint)
{
    sfColor black = {0, 0, 0, 255};

    COLOR = black;
    if (paint->tool.primary) {
        paint->tool.primary_color = black;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, black);
    } else {
        paint->tool.secondary_color = black;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, black);
    }
}

void dark_gray(paint_t *paint)
{
    sfColor dark_gray = {127, 127, 127, 255};

    COLOR = dark_gray;
    if (paint->tool.primary) {
        paint->tool.primary_color = dark_gray;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, dark_gray);
    } else {
        paint->tool.secondary_color = dark_gray;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, dark_gray);
    }
}

void dark_red(paint_t *paint)
{
    sfColor dark_red = {126, 0, 21, 255};

    COLOR = dark_red;
    if (paint->tool.primary) {
        paint->tool.primary_color = dark_red;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, dark_red);
    } else {
        paint->tool.secondary_color = dark_red;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, dark_red);
    }
}

void red(paint_t *paint)
{
    sfColor red = {237, 28, 36, 255};

    COLOR = red;
    if (paint->tool.primary) {
        paint->tool.primary_color = red;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, red);
    } else {
        paint->tool.secondary_color = red;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, red);
    }
}

void orange(paint_t *paint)
{
    sfColor orange = {255, 127, 39, 255};

    COLOR = orange;
    if (paint->tool.primary) {
        paint->tool.primary_color = orange;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, orange);
    } else {
        paint->tool.secondary_color = orange;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, orange);
    }
}
