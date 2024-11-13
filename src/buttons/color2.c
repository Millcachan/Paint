/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color2
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void yellow(paint_t *paint)
{
    sfColor yellow = {252, 239, 0, 255};

    COLOR = yellow;
    if (paint->tool.primary) {
        paint->tool.primary_color = yellow;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, yellow);
    } else {
        paint->tool.secondary_color = yellow;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, yellow);
    }
}

void green(paint_t *paint)
{
    sfColor green = {34, 177, 76, 255};

    COLOR = green;
    if (paint->tool.primary) {
        paint->tool.primary_color = green;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, green);
    } else {
        paint->tool.secondary_color = green;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, green);
    }
}

void blue(paint_t *paint)
{
    sfColor blue = {0, 162, 232, 255};

    COLOR = blue;
    if (paint->tool.primary) {
        paint->tool.primary_color = blue;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, blue);
    } else {
        paint->tool.secondary_color = blue;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, blue);
    }
}

void dark_blue(paint_t *paint)
{
    sfColor dark_blue = {63, 72, 204, 255};

    COLOR = dark_blue;
    if (paint->tool.primary) {
        paint->tool.primary_color = dark_blue;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, dark_blue);
    } else {
        paint->tool.secondary_color = dark_blue;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, dark_blue);
    }
}

void purple(paint_t *paint)
{
    sfColor purple = {163, 73, 164, 255};

    COLOR = purple;
    if (paint->tool.primary) {
        paint->tool.primary_color = purple;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, purple);
    } else {
        paint->tool.secondary_color = purple;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, purple);
    }
}
