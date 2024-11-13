/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** rotation
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void rotation_clockwise(paint_t *paint)
{
    paint->canva.angle += 90.0f;
    SPRITE_SETROTATION(paint->canva.sprite, paint->canva.angle);
    paint->queue.angle += 90.0f;
    SPRITE_SETROTATION(paint->queue.sprite, paint->queue.angle);
}

void rotation_counter(paint_t *paint)
{
    paint->canva.angle -= 90.0f;
    SPRITE_SETROTATION(paint->canva.sprite, paint->canva.angle);
    paint->queue.angle -= 90.0f;
    SPRITE_SETROTATION(paint->queue.sprite, paint->queue.angle);
}
