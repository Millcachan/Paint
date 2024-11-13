/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** colorsheet
*/

#include "paint.h"

void use_colorsheet(paint_t *paint)
{
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);
    sfVector2f pos = SPRITE_GETPOS(paint->colorsheet.sprite);
    sfFloatRect rect = SPRITE_GETGBOUNDS(paint->colorsheet.sprite);
    sfColor color;

    if (RECT_CONTAINS(&rect, (float)mouse.x, (float)mouse.y)) {
        color = sfImage_getPixel(paint->colorsheet.image,
        (unsigned int)((mouse.x - (int)pos.x) / 2),
        (unsigned int)((mouse.y - (int)pos.y) / 2));
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
