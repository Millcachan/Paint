/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** rectangle_shape
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

static void draw_square(paint_t *paint, int size, sfVector2i mouse)
{
    for (int y = mouse.y - size; y <= mouse.y + size; ++y)
        for (int x = mouse.x - size; x <= mouse.x + size; ++x)
            draw_pixel(paint, x, y);
}

static void draw_square_line(paint_t *paint, sfVector2i pos1, sfVector2i pos2)
{
    int dx = pos2.x - pos1.x;
    int dy = pos2.y - pos1.y;
    int x = pos1.x;
    int y = pos1.y;

    draw_square(paint, paint->tool.size, (sfVector2i){pos1.x, pos1.y});
    while (x != pos2.x) {
        y = pos1.y + dy * (x - pos1.x) / dx;
        draw_square(paint, paint->tool.size, (sfVector2i){x, y});
        x = (pos1.x > pos2.x) ? x - 1 : x + 1;
    }
    y = pos1.y;
    while (y != pos2.y) {
        x = pos1.x + dx * (y - pos1.y) / dy;
        draw_square(paint, paint->tool.size, (sfVector2i){x, y});
        y = (pos1.y > pos2.y) ? y - 1 : y + 1;
    }
}

void draw_rectangle(paint_t *paint)
{
    sfVector2i pos1 = paint->queue.pos1;
    sfVector2i pos2 = paint->queue.pos2;

    if (paint->queue.pos1.x == -1 || paint->queue.pos1.y == -1) {
        paint->queue.pos1 = MOUSE_GETPOS(paint->screen.window);
    } else {
        paint->queue.pos2 = MOUSE_GETPOS(paint->screen.window);
        pos1 = paint->queue.pos1;
        pos2 = paint->queue.pos2;
        reset_canva(paint->queue.pixels);
        draw_square_line(paint, pos1, (sfVector2i){pos1.x, pos2.y});
        draw_square_line(paint, pos1, (sfVector2i){pos2.x, pos1.y});
        draw_square_line(paint, (sfVector2i){pos2.x, pos1.y}, pos2);
        draw_square_line(paint, (sfVector2i){pos1.x, pos2.y}, pos2);
    }
}
