/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** ctrl
*/

#include "my.h"
#include "paint.h"
#include "macro.h"
#include "drawing.h"

void undo(paint_t *paint)
{
    cpy_canva(paint->ctrl.redo, paint->canva.pixels);
    cpy_canva(paint->canva.pixels, paint->ctrl.undo);
}

void redo(paint_t *paint)
{
    cpy_canva(paint->ctrl.undo, paint->canva.pixels);
    cpy_canva(paint->canva.pixels, paint->ctrl.redo);
}
