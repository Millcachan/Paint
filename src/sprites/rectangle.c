/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** rectangle
*/

#include "paint.h"
#include "macro.h"

sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *rect = RECTANGLE_CREATE();

    RECTANGLE_SETSIZE(rect, size);
    RECTANGLE_SETPOS(rect, pos);
    return rect;
}
