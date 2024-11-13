/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** exit
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void exit_paint(paint_t *paint)
{
    CLOSE(paint->screen.window);
}
