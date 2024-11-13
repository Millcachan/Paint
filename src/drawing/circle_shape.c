/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** circle_shape
*/

#include <math.h>
#include <stdio.h>
#include "macro.h"
#include "paint.h"
#include "drawing.h"

static void draw_pixel(paint_t *paint, int x, int y)
{
    int index = ((y - 324) * 1152 + x - 384) * 4;

    if (index >= 0 && index < 1152 * 648 * 4) {
        paint->queue.pixels[index + 0] = paint->tool.color.r;
        paint->queue.pixels[index + 1] = paint->tool.color.g;
        paint->queue.pixels[index + 2] = paint->tool.color.b;
        paint->queue.pixels[index + 3] = paint->tool.color.a;
    }
}

static void compute_circle_shape(paint_t *paint, sfVector2i pos1,
    sfVector2i pos2, int rad)
{
    int dist;

    dist = (int)sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x)
    + (pos1.y - pos2.y) * (pos1.y - pos2.y));
    if (fabs((double)(dist - rad)) <= paint->tool.size)
        draw_pixel(paint, pos1.x, pos1.y);
}

static void circle_shape_loop(paint_t *paint, sfVector2i pos,
    int rad, int size)
{
    for (int x = pos.x - rad - size; x <= pos.x + rad + size; ++x)
        for (int y = pos.y - rad - size; y <= pos.y + rad + size; ++y)
            compute_circle_shape(paint, (sfVector2i){x, y}, pos, rad);
}

void draw_circle_shape(paint_t *paint)
{
    sfVector2i pos = paint->queue.pos1;
    sfVector2i pos2 = paint->queue.pos2;
    int rad = (int)sqrt((pos2.x - pos.x) * (pos2.x - pos.x)
    + (pos2.y - pos.y) * (pos2.y - pos.y));

    if (paint->queue.pos1.x == -1 || paint->queue.pos1.y == -1) {
        paint->queue.pos1 = MOUSE_GETPOS(paint->screen.window);
    } else {
        paint->queue.pos2 = MOUSE_GETPOS(paint->screen.window);
        pos = paint->queue.pos1;
        pos2 = paint->queue.pos2;
        reset_canva(paint->queue.pixels);
        circle_shape_loop(paint, pos, rad, paint->tool.size);
    }
}
