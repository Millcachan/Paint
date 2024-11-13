/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** thickness
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

void change_active_button(paint_t *paint, sfBool active, int ID)
{
    button_t *current = paint->buttons;

    while (current) {
        if (current->ID == ID)
            current->active = active;
        current = current->next;
    }
}

void thickness(paint_t *paint)
{
    paint->thickness.thickness = !paint->thickness.thickness;
    change_active_button(paint, paint->thickness.thickness, 45);
    change_active_button(paint, paint->thickness.thickness, 46);
    change_active_button(paint, paint->thickness.thickness, 47);
    change_active_button(paint, paint->thickness.thickness, 48);
}
