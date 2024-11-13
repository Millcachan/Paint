/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** button
*/

#include "my.h"
#include "macro.h"
#include <stdio.h>
#include "button.h"
#include "parser.h"
#include <stdlib.h>
#include <string.h>

sfBool is_rect_button_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect rect = RECTANGLE_GETGBOUNDS(button->rect);
    sfVector2f pos = {(float)event->x, (float)event->y};

    return RECT_CONTAINS(&rect, pos.x, pos.y);
}

sfBool is_circle_button_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfVector2f circle_pos =
    {button->pos.x + button->radius, button->pos.y + button->radius};
    sfVector2f mouse_pos = {(float)event->x, (float)event->y};
    float dx = circle_pos.x - mouse_pos.x;
    float dy = circle_pos.y - mouse_pos.y;

    return (dx * dx + dy * dy) <= (button->radius * button->radius);
}

sfBool is_rect_button_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect rect = RECTANGLE_GETGBOUNDS(button->rect);
    sfVector2f pos = {(float)event->x, (float)event->y};

    return RECT_CONTAINS(&rect, pos.x, pos.y);
}

sfBool is_circle_button_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfVector2f circle_pos =
    {button->pos.x + button->radius, button->pos.y + button->radius};
    sfVector2f mouse_pos = {(float)event->x, (float)event->y};
    float dx = circle_pos.x - mouse_pos.x;
    float dy = circle_pos.y - mouse_pos.y;

    return (dx * dx + dy * dy) <= (button->radius * button->radius);
}

static void set_rect_button(button_t *button, sfVector2f pos, sfVector2f size)
{
    button->rect = RECTANGLE_CREATE();
    button->is_clicked = is_rect_button_clicked;
    button->is_hover = is_rect_button_hover;
    RECTANGLE_SETPOS(button->rect, pos);
    RECTANGLE_SETSIZE(button->rect, size);
    RECTANGLE_SETOUTLINETHICK(button->rect, 1.0f);
}

static void set_circle_button(button_t *button, sfVector2f pos, float radius)
{
    button->circle = CIRCLE_CREATE();
    button->is_clicked = is_circle_button_clicked;
    button->is_hover = is_circle_button_hover;
    CIRCLE_SETPOS(button->circle, pos);
    CIRCLE_SETRAD(button->circle, radius);
    CIRCLE_SETOUTILETHICK(button->circle, 1.0f);
}

static void set_new_button(button_t *button, char **infos)
{
    static int current_ID = 0;

    button->pos =
    (sfVector2f){(float)my_getnbr(infos[1]), (float)my_getnbr(infos[2])};
    button->ID = current_ID;
    button->shape = (int)my_getnbr(infos[0]);
    if (button->shape) {
        button->size =
        (sfVector2f){(float)my_getnbr(infos[3]), (float)my_getnbr(infos[4])};
        set_rect_button(button, button->pos, button->size);
        button->active = (int)my_getnbr(infos[5]);
    } else {
        button->radius = (float)my_getnbr(infos[3]);
        set_circle_button(button, button->pos, button->radius);
        button->active = (int)my_getnbr(infos[4]);
    }
    for (int i = 0; button_function[i].function_ptr; i++)
        if (button_function[i].id == button->ID)
            button->action = button_function[i].function_ptr;
    current_ID++;
}

static button_t *create_new_button(char *infos)
{
    char **split_infos = split_numbers(infos);
    button_t *new_button;

    if (!split_infos)
        return NULL;
    new_button = malloc((size_t)(sizeof(button_t)));
    set_new_button(new_button, split_infos);
    for (int i = 0; split_infos[i]; i++)
        free(split_infos[i]);
    free(split_infos);
    return new_button;
}

button_t *add_button(button_t *head, char *infos)
{
    button_t *new_button = create_new_button(infos);

    if (!new_button)
        return head;
    new_button->next = head;
    return new_button;
}
