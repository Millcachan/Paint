/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** pixel
*/

#include <math.h>
#include <stdio.h>
#include "macro.h"
#include "paint.h"

static void draw_pixel(paint_t *paint, int x, int y)
{
    int index = ((y - 324) * 1152 + x - 384) * 4;
    sfColor color = paint->tool.color;

    if (ACTION == ERASER)
        color = sfWhite;
    if (index >= 0 && index < 1152 * 648 * 4) {
        paint->canva.pixels[index + 0] = color.r;
        paint->canva.pixels[index + 1] = color.g;
        paint->canva.pixels[index + 2] = color.b;
        paint->canva.pixels[index + 3] = color.a;
    }
}

static void draw_square(paint_t *paint, int size, sfVector2i mouse)
{
    for (int y = mouse.y - size; y <= mouse.y + size; ++y)
        for (int x = mouse.x - size; x <= mouse.x + size; ++x)
            draw_pixel(paint, x, y);
}

static void compute_radius(paint_t *paint, sfVector2i mouse,
    sfVector2i pos, int size)
{
    double distance = sqrt(pow(pos.x - mouse.x, 2) + pow(pos.y - mouse.y, 2));

    if (distance <= size)
        draw_pixel(paint, pos.x, pos.y);
}

static void draw_circle(paint_t *paint, int size, sfVector2i mouse)
{
    sfVector2i pos;

    for (int y = mouse.y - size; y <= mouse.y + size; ++y) {
        for (int x = mouse.x - size; x <= mouse.x + size; ++x) {
            pos.x = x;
            pos.y = y;
            compute_radius(paint, mouse, pos, size);
        }
    }
}

static void get_pos(paint_t *paint, sfVector2i mouse)
{
    if (paint->canva.pos1.x == -1 || paint->canva.pos1.y == -1) {
        paint->canva.pos1.x = mouse.x;
        paint->canva.pos1.y = mouse.y;
        paint->canva.pos2.x = mouse.x;
        paint->canva.pos2.y = mouse.y;
    } else {
        paint->canva.pos2.x = paint->canva.pos1.x;
        paint->canva.pos2.y = paint->canva.pos1.y;
        paint->canva.pos1.x = mouse.x;
        paint->canva.pos1.y = mouse.y;
    }
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

static void draw_circle_line(paint_t *paint, sfVector2i pos1, sfVector2i pos2)
{
    int dx = pos2.x - pos1.x;
    int dy = pos2.y - pos1.y;
    int x = pos1.x;
    int y = pos1.y;

    draw_circle(paint, paint->tool.size, (sfVector2i){pos1.x, pos1.y});
    while (x != pos2.x) {
        y = pos1.y + dy * (x - pos1.x) / dx;
        draw_circle(paint, paint->tool.size, (sfVector2i){x, y});
        x = (pos1.x > pos2.x) ? x - 1 : x + 1;
    }
    y = pos1.y;
    while (y != pos2.y) {
        x = pos1.x + dx * (y - pos1.y) / dy;
        draw_circle(paint, paint->tool.size, (sfVector2i){x, y});
        y = (pos1.y > pos2.y) ? y - 1 : y + 1;
    }
}

void draw_canva(paint_t *paint)
{
    sfFloatRect pos = SPRITE_GETGBOUNDS(paint->canva.sprite);
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);

    get_pos(paint, mouse);
    if (RECT_CONTAINS(&pos, (float)mouse.x, (float)mouse.y)) {
        if (paint->tool.shape)
            draw_square_line(paint, paint->canva.pos1, paint->canva.pos2);
        else
            draw_circle_line(paint, paint->canva.pos1, paint->canva.pos2);
    }
}
