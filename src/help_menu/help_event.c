/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** help_event.c
*/

#include "my.h"
#include "paint.h"
#include "help.h"

void help_events(sfEvent *event, sfRenderWindow *window, int *i)
{
    if (event->type == sfEvtClosed)
        CLOSE(window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeySpace)
            *i = *i + 1;
        if (event->key.code == sfKeySpace && *i == 3)
            CLOSE(window);
    }
}
