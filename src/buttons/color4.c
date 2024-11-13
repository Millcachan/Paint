/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** color4
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void beige(paint_t *paint)
{
    sfColor beige = {239, 228, 176, 255};

    COLOR = beige;
    if (paint->tool.primary) {
        paint->tool.primary_color = beige;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, beige);
    } else {
        paint->tool.secondary_color = beige;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, beige);
    }
}

void lime(paint_t *paint)
{
    sfColor lime = {172, 219, 29, 255};

    COLOR = lime;
    if (paint->tool.primary) {
        paint->tool.primary_color = lime;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, lime);
    } else {
        paint->tool.secondary_color = lime;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, lime);
    }
}

void cyan(paint_t *paint)
{
    sfColor cyan = {148, 210, 226, 255};

    COLOR = cyan;
    if (paint->tool.primary) {
        paint->tool.primary_color = cyan;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, cyan);
    } else {
        paint->tool.secondary_color = cyan;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, cyan);
    }
}

void clay(paint_t *paint)
{
    sfColor clay = {111, 144, 188, 255};

    COLOR = clay;
    if (paint->tool.primary) {
        paint->tool.primary_color = clay;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, clay);
    } else {
        paint->tool.secondary_color = clay;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, clay);
    }
}

void lila(paint_t *paint)
{
    sfColor lila = {200, 191, 231, 255};

    COLOR = lila;
    if (paint->tool.primary) {
        paint->tool.primary_color = lila;
        CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, lila);
    } else {
        paint->tool.secondary_color = lila;
        CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, lila);
    }
}
