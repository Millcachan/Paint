/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** event
*/

#include <math.h>
#include <stdio.h>
#include "macro.h"
#include "paint.h"
#include "button.h"
#include "drawing.h"

void event_button_clicked(paint_t *paint, button_t *current)
{
    if (current->is_clicked(current, &paint->event.mouseButton))
        current->action(paint);
}

void event_button_hover(paint_t *paint, button_t *current)
{
    if (current->shape) {
        if (current->is_hover(current, &paint->event.mouseMove)) {
            RECTANGLE_FILLCOLOR(current->rect, (sfColor){150, 150, 150, 90});
            RECTANGLE_SETOUTLINECOLOR(current->rect, (sfColor){0, 0, 0, 100});
        } else {
            RECTANGLE_FILLCOLOR(current->rect, sfTransparent);
            RECTANGLE_SETOUTLINECOLOR(current->rect, sfTransparent);
        }
    } else {
        if (current->is_hover(current, &paint->event.mouseMove)) {
            CIRCLE_SETFILLCOLOR(current->circle, (sfColor){150, 150, 150, 90});
            CIRCLE_SETOUTLINECOLOR(current->circle, (sfColor){0, 0, 0, 100});
        } else {
            CIRCLE_SETFILLCOLOR(current->circle, sfTransparent);
            CIRCLE_SETOUTLINECOLOR(current->circle, sfTransparent);
        }
    }
}

void event_button(paint_t *paint)
{
    button_t *current = paint->buttons;

    while (current) {
        if (paint->pressed && current->active)
            event_button_clicked(paint, current);
        if (current->active)
            event_button_hover(paint, current);
        current = current->next;
    }
}

static void update_dropdown(paint_t *paint)
{
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);
    sfFloatRect rect = SPRITE_GETGBOUNDS(paint->thickness.sprite.sprite);

    if (!RECT_CONTAINS(&rect, (float)mouse.x, (float)mouse.y)) {
        paint->thickness.thickness = 0;
        change_active_button(paint, 0, 45);
        change_active_button(paint, 0, 46);
        change_active_button(paint, 0, 47);
        change_active_button(paint, 0, 48);
    }
}

static void reset_clic(paint_t *paint)
{
    paint->tool.security = 0;
    paint->canva.pos1 = (sfVector2i){-1, -1};
    paint->canva.pos2 = (sfVector2i){-1, -1};
    paint->queue.pos1 = (sfVector2i){-1, -1};
    paint->queue.pos2 = (sfVector2i){-1, -1};
    paint->pressed = FALSE;
}

static void update_clic(paint_t *paint)
{
    sfVector2i mouse = MOUSE_GETPOS(paint->screen.window);
    sfFloatRect rect = SPRITE_GETGBOUNDS(paint->colorsheet.sprite);

    if (paint->event.type == sfEvtMouseButtonPressed) {
        paint->pressed = TRUE;
        update_dropdown(paint);
    }
    if (paint->event.type == sfEvtMouseButtonReleased) {
        reset_clic(paint);
        if (ACTION == LINE || ACTION == CIRCLE || ACTION || RECTANGLE) {
            merge_layers(paint->canva.pixels, paint->queue.pixels);
            reset_canva(paint->queue.pixels);
        }
        ACTION = (RECT_CONTAINS(&rect, (float)mouse.x, (float)mouse.y)
        && ACTION == COLORSHEET) ? PENCIL : ACTION;
        if (!is_same_canva(paint->canva.pixels, paint->ctrl.queue)) {
            cpy_canva(paint->ctrl.undo, paint->ctrl.queue);
            cpy_canva(paint->ctrl.queue, paint->canva.pixels);
        }
    }
}

static void action(paint_t *paint)
{
    if (paint->pressed && paint->thickness.thickness == 0) {
        if (ACTION == COLORPICKER)
            use_colorpicker(paint);
        if (ACTION == COLORSHEET)
            use_colorsheet(paint);
        if (ACTION == BUCKET)
            bucket_fill(paint);
        if (ACTION == ERASER)
            draw_canva(paint, 1);
        if (ACTION == PENCIL || ACTION == BRUSH)
            draw_canva(paint, 0);
        if (ACTION == LINE)
            draw_line(paint);
        if (ACTION == RECTANGLE)
            draw_rectangle(paint);
        if (ACTION == CIRCLE)
            draw_circle_shape(paint);
    }
}

static void keybinds(paint_t *paint)
{
    if (paint->event.key.control && KEYCODE == sfKeyZ)
        undo(paint);
    if (paint->event.key.control && KEYCODE == sfKeyY)
        redo(paint);
    if (paint->event.key.control && KEYCODE == sfKeyB)
        bucket(paint);
    if (paint->event.key.control && KEYCODE == sfKeyP)
        pencil(paint);
    if (paint->event.key.control && KEYCODE == sfKeyC)
        colorpicker(paint);
    if (paint->event.key.control && KEYCODE == sfKeyE)
        eraser(paint);
    if (paint->event.key.control && KEYCODE == sfKeyT)
        brush(paint);
    if (paint->event.key.control && KEYCODE == sfKeyY)
        redo(paint);
    if (paint->event.key.control && KEYCODE == sfKeyS)
        save(paint);
}

static void update_key(paint_t *paint)
{
    if (paint->event.type == sfEvtKeyPressed) {
        if (KEYCODE == sfKeyEscape)
            ACTION = PENCIL;
        keybinds(paint);
    }
}

void event_manager(paint_t *paint)
{
    if (paint->event.type == sfEvtClosed)
        CLOSE(paint->screen.window);
    update_key(paint);
    update_clic(paint);
    event_button(paint);
    action(paint);
}
