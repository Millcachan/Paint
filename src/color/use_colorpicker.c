/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** colorpicker
*/

#include <stdio.h>
#include "macro.h"
#include "paint.h"

void use_colorpicker(paint_t *paint)
{
    sfFloatRect pos = SPRITE_GETGBOUNDS(paint->canva.sprite);
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);
    sfColor color;

    if (RECT_CONTAINS(&pos, (float)mouse.x, (float)mouse.y)) {
        mouse.x -= 384;
        mouse.y -= 324;
        color.r = paint->canva.pixels[((mouse.y * 1152) + mouse.x) * 4 + 0];
        color.g = paint->canva.pixels[((mouse.y * 1152) + mouse.x) * 4 + 1];
        color.b = paint->canva.pixels[((mouse.y * 1152) + mouse.x) * 4 + 2];
        color.a = paint->canva.pixels[((mouse.y * 1152) + mouse.x) * 4 + 3];
        paint->tool.color = color;
        if (paint->tool.primary) {
            paint->tool.primary_color = color;
            CIRCLE_SETFILLCOLOR(paint->tool.primary_circle, color);
        } else {
            paint->tool.secondary_color = color;
            CIRCLE_SETFILLCOLOR(paint->tool.secondary_circle, color);
        }
    }
}
