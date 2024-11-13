/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** account_event.c
*/

#include "account.h"

void account_events(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        CLOSE(window);
}
