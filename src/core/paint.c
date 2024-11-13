/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** paint
*/

#include "init.h"
#include "free.h"
#include "macro.h"
#include "paint.h"
#include "update.h"
#include "eventmanager.h"

int my_paint(void)
{
    paint_t paint = init_paint();

    while (IS_OPEN(paint.screen.window)) {
        while (POLL_EVENT(paint.screen.window, &paint.event))
            event_manager(&paint);
        update(&paint);
    }
    free_paint(&paint);
    return SUCCESS;
}
