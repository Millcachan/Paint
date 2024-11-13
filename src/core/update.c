/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** update
*/

#include "paint.h"
#include "macro.h"

static void update_colorsheet(paint_t *paint)
{
    if (paint->tool.action == COLORSHEET)
        SPRITE_DRAW(paint->screen.window, paint->colorsheet.sprite, NULL);
}

static void update_gui(paint_t *paint)
{
    SPRITE_DRAW(paint->screen.window, paint->gui.background.sprite, NULL);
}

static void update_buttons(paint_t *paint)
{
    button_t *current = paint->buttons;

    while (current) {
        if (current->shape && current->active)
            RECTANGLE_DRAW(paint->screen.window, current->rect, NULL);
        if (!current->shape && current->active)
            CIRCLE_DRAW(paint->screen.window,
            current->circle, NULL);
        current = current->next;
    }
    CIRCLE_DRAW(paint->screen.window, paint->tool.primary_circle, NULL);
    CIRCLE_DRAW(paint->screen.window, paint->tool.secondary_circle, NULL);
}

static void update_canva(paint_t *paint)
{
    TEXTURE_UPDATE(paint->canva.texture,
    (sfUint8 *)paint->canva.pixels, 1152, 648, 0, 0);
    SPRITE_SETTEXTURE(paint->canva.sprite, paint->canva.texture, sfTrue);
    SPRITE_DRAW(paint->screen.window, paint->canva.sprite, NULL);
}

static void update_queue(paint_t *paint)
{
    TEXTURE_UPDATE(paint->queue.texture,
    (sfUint8 *)paint->queue.pixels, 1152, 648, 0, 0);
    SPRITE_SETTEXTURE(paint->queue.sprite, paint->queue.texture, sfTrue);
    SPRITE_DRAW(paint->screen.window, paint->queue.sprite, NULL);
}

static void update_thickness(paint_t *paint)
{
    if (paint->thickness.thickness)
        SPRITE_DRAW(paint->screen.window,
        paint->thickness.sprite.sprite, NULL);
}

static void update_position(sfRenderWindow *window, sfSprite *cursor)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    SPRITE_SETPOS(cursor, (sfVector2f){(float)pos.x, (float)pos.y - 16});
    SPRITE_DRAW(window, cursor, NULL);
}

static void update_cursor(paint_t *paint)
{
    switch (ACTION) {
    case ERASER:
        update_position(paint->screen.window, paint->cursor.eraser_sprite);
        break;
    case BRUSH:
    case PENCIL:
        update_position(paint->screen.window, paint->cursor.pencil_sprite);
        break;
    case BUCKET:
        update_position(paint->screen.window, paint->cursor.bucket_sprite);
        break;
    case COLORPICKER:
        update_position(paint->screen.window, paint->cursor.pipette_sprite);
        break;
    default:
        sfRenderWindow_setMouseCursorVisible(paint->screen.window, sfTrue);
        break;
    }
}

void update(paint_t *paint)
{
    CLEAR(paint->screen.window, sfBlack);
    update_gui(paint);
    update_canva(paint);
    update_queue(paint);
    update_thickness(paint);
    update_buttons(paint);
    update_colorsheet(paint);
    update_cursor(paint);
    DISPLAY(paint->screen.window);
}
