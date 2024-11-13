/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** free
*/

#include "paint.h"
#include "macro.h"

static void free_buttons(button_t *head)
{
    button_t *temp = NULL;

    while (head) {
        temp = head->next;
        if (head->shape)
            RECTANGLE_DESTROY(head->rect);
        else
            CIRCLE_DESTROY(head->circle);
        free(head);
        head = temp;
    }
}

static void free_gui_cursor(gui_t *gui, cursor_t *cursor)
{
    SPRITE_DESTROY(gui->background.sprite);
    TEXTURE_DESTROY(gui->background.texture);
    SPRITE_DESTROY(cursor->bucket_sprite);
    SPRITE_DESTROY(cursor->pencil_sprite);
    SPRITE_DESTROY(cursor->pipette_sprite);
    SPRITE_DESTROY(cursor->eraser_sprite);
    TEXTURE_DESTROY(cursor->bucket_text);
    TEXTURE_DESTROY(cursor->pencil_text);
    TEXTURE_DESTROY(cursor->pipette_text);
    TEXTURE_DESTROY(cursor->eraser_text);
}

static void free_colorsheet(colorsheet_t *colorsheet)
{
    SPRITE_DESTROY(colorsheet->sprite);
    TEXTURE_DESTROY(colorsheet->texture);
    IMAGE_DESTROY(colorsheet->image);
}

static void free_tool(tool_t *tool)
{
    CIRCLE_DESTROY(tool->primary_circle);
    CIRCLE_DESTROY(tool->secondary_circle);
}

static void free_canva(canva_t *canva)
{
    SPRITE_DESTROY(canva->sprite);
    TEXTURE_DESTROY(canva->texture);
    free(canva->pixels);
}

static void free_ctrl(ctrl_t *ctrl)
{
    free(ctrl->queue);
    free(ctrl->redo);
    free(ctrl->undo);
}

void free_paint(paint_t *paint)
{
    WINDOW_DESTROY(paint->screen.window);
    free_colorsheet(&paint->colorsheet);
    free_buttons(paint->buttons);
    free_canva(&paint->canva);
    free_canva(&paint->queue);
    free_tool(&paint->tool);
    free_ctrl(&paint->ctrl);
    free_gui_cursor(&paint->gui, &paint->cursor);
}
