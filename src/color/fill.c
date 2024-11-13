/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** fill
*/

#include <stdio.h>
#include "macro.h"
#include "paint.h"

static sfColor get_color_from_pos(sfUint8 *pixels, sfVector2i pos)
{
    sfColor color;

    color.r = pixels[((pos.y * 1152) + pos.x) * 4 + 0];
    color.g = pixels[((pos.y * 1152) + pos.x) * 4 + 1];
    color.b = pixels[((pos.y * 1152) + pos.x) * 4 + 2];
    color.a = pixels[((pos.y * 1152) + pos.x) * 4 + 3];
    return color;
}

stack_t *add_to_queue(stack_t *head, int x, int y)
{
    stack_t *new_pos;
    stack_t *temp;
    stack_t *current;

    new_pos = malloc(sizeof(stack_t));
    if (!new_pos)
        return head;
    new_pos->pos = (sfVector2i){x, y};
    new_pos->next = NULL;
    if (head == NULL)
        return new_pos;
    else {
        current = head;
        if (current->next)
            current = current->next;
        temp = current->next;
        current->next = new_pos;
        new_pos->next = temp;
        return head;
    }
}

static sfBool same_color(sfColor c1, sfColor c2)
{
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

static void change_color_from_pixels(sfUint8 *pixels, int index, sfColor tool)
{
    pixels[index + 0] = tool.r;
    pixels[index + 1] = tool.g;
    pixels[index + 2] = tool.b;
    pixels[index + 3] = tool.a;
}

void bfs(sfUint8 *pixels, sfVector2i first_pos, sfColor base, sfColor tool)
{
    stack_t *queue = NULL;
    sfVector2i pos;
    int index;

    queue = add_to_queue(queue, first_pos.x, first_pos.y);
    while (queue) {
        pos = queue->pos;
        index = ((pos.y * 1152) + pos.x) * 4;
        if (pos.x < 0 || pos.x >= 1152 || pos.y < 0 || pos.y >= 648 ||
            !same_color(base, get_color_from_pos(pixels, pos))) {
            queue = queue->next;
            continue;
        }
        change_color_from_pixels(pixels, index, tool);
        queue = add_to_queue(queue, pos.x, pos.y - 1);
        queue = add_to_queue(queue, pos.x + 1, pos.y);
        queue = add_to_queue(queue, pos.x, pos.y + 1);
        queue = add_to_queue(queue, pos.x - 1, pos.y);
        queue = queue->next;
    }
}

void bucket_fill(paint_t *paint)
{
    sfFloatRect pos = SPRITE_GETGBOUNDS(paint->canva.sprite);
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);
    sfColor color;

    if (paint->tool.security)
        return;
    if (RECT_CONTAINS(&pos, (float)mouse.x, (float)mouse.y)) {
        mouse.x -= 384;
        mouse.y -= 324;
        color = get_color_from_pos(paint->canva.pixels, mouse);
        if (same_color(color, paint->tool.color))
            return;
        bfs(paint->canva.pixels, mouse, color, paint->tool.color);
    }
    paint->tool.security = 1;
}
