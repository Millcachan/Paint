/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** init
*/

#include <stdio.h>
#include "paint.h"
#include "macro.h"
#include "button.h"
#include "sprite.h"
#include "rectangle.h"

static void init_screen(screen_t *screen, gui_t *gui)
{
    sfFloatRect rect;

    gui->background = create_sprite("asset/paint.png", (sfVector2f){0, 0});
    rect = SPRITE_GETGBOUNDS(gui->background.sprite);
    screen->width = rect.width;
    screen->height = rect.height;
    screen->mode = (sfVideoMode){1920, 1080, 32};
    screen->window = WINDOW_CREATE(screen->mode, "My Paint", sfClose, NULL);
}

static button_t *init_buttons(void)
{
    FILE *file = fopen("config/buttons.conf", "r");
    button_t *head = NULL;
    char *buffer = NULL;
    size_t size = 0;

    while (getline(&buffer, &size, file) != -1)
        head = add_button(head, buffer);
    free(buffer);
    fclose(file);
    return head;
}

static void init_canva(canva_t *canva, sfUint8 rgba)
{
    sfFloatRect rect;

    canva->sprite = SPRITE_CREATE();
    canva->texture = TEXTURE_CREATE(1152, 648);
    canva->pixels = malloc(sizeof(sfUint8) * (1152 * 648 * 4));
    for (int i = 0; i < (1152 * 648 * 4); i++)
        canva->pixels[i] = rgba;
    SPRITE_SETPOS(canva->sprite, (sfVector2f){960.0f, 648.0f});
    TEXTURE_UPDATE(canva->texture, (sfUint8 *)canva->pixels, 1152, 648, 0, 0);
    SPRITE_SETTEXTURE(canva->sprite, canva->texture, sfTrue);
    SPRITE_SETORIGIN(canva->sprite, (sfVector2f){576.0f, 324.0f});
    canva->pos1 = (sfVector2i){-1, -1};
    canva->pos2 = (sfVector2i){-1, -1};
    rect = SPRITE_GETGBOUNDS(canva->sprite);
    canva->height = rect.height;
    canva->width = rect.width;
    canva->rotation_x = 1.0f;
    canva->rotation_y = 1.0f;
    canva->angle = 0.0f;
}

static void set_colorcircle(tool_t *tool)
{
    sfColor gray = (sfColor){127, 127, 127, 255};

    tool->primary_circle = CIRCLE_CREATE();
    tool->secondary_circle = CIRCLE_CREATE();
    CIRCLE_SETRAD(tool->primary_circle, 12.0f);
    CIRCLE_SETRAD(tool->secondary_circle, 12.0f);
    CIRCLE_SETOUTILETHICK(tool->primary_circle, 1.0f);
    CIRCLE_SETFILLCOLOR(tool->primary_circle, sfBlack);
    CIRCLE_SETOUTLINECOLOR(tool->primary_circle, gray);
    CIRCLE_SETOUTILETHICK(tool->secondary_circle, 1.0f);
    CIRCLE_SETOUTLINECOLOR(tool->secondary_circle, gray);
    CIRCLE_SETFILLCOLOR(tool->secondary_circle, sfWhite);
    CIRCLE_SETPOS(tool->primary_circle, (sfVector2f){530, 85});
    CIRCLE_SETPOS(tool->secondary_circle, (sfVector2f){530, 121});
}

static void init_tool(tool_t *tool)
{
    tool->size = 5;
    tool->shape = 1;
    tool->primary = 1;
    tool->color = sfBlack;
    tool->action = PENCIL;
    tool->primary_color = sfBlack;
    tool->secondary_color = sfWhite;
    set_colorcircle(tool);
}

static void init_cursor(cursor_t *cursor)
{
    cursor->bucket_text = TEXTURE_CREATE_FILE("asset/cursors/bucket.png", 0);
    cursor->eraser_text = TEXTURE_CREATE_FILE("asset/cursors/eraser.png", 0);
    cursor->pencil_text = TEXTURE_CREATE_FILE("asset/cursors/pencil.png", 0);
    cursor->pipette_text = TEXTURE_CREATE_FILE("asset/cursors/pipette.png", 0);
    cursor->bucket_sprite = SPRITE_CREATE();
    cursor->eraser_sprite = SPRITE_CREATE();
    cursor->pencil_sprite = SPRITE_CREATE();
    cursor->pipette_sprite = SPRITE_CREATE();
    SPRITE_SETTEXTURE(cursor->bucket_sprite, cursor->bucket_text, 0);
    SPRITE_SETTEXTURE(cursor->eraser_sprite, cursor->eraser_text, 0);
    SPRITE_SETTEXTURE(cursor->pencil_sprite, cursor->pencil_text, 0);
    SPRITE_SETTEXTURE(cursor->pipette_sprite, cursor->pipette_text, 0);
    SPRITE_SETSCALE(cursor->bucket_sprite, (sfVector2f){0.25, 0.25});
    SPRITE_SETSCALE(cursor->pencil_sprite, (sfVector2f){0.25, 0.25});
    SPRITE_SETSCALE(cursor->pipette_sprite, (sfVector2f){0.25, 0.25});
    SPRITE_SETSCALE(cursor->eraser_sprite, (sfVector2f){0.25, 0.25});
    SPRITE_SETORIGIN(cursor->pencil_sprite, (sfVector2f){0, 64});
    SPRITE_SETORIGIN(cursor->eraser_sprite, (sfVector2f){0, 64});
    SPRITE_SETORIGIN(cursor->pipette_sprite, (sfVector2f){0, 64});
    SPRITE_SETORIGIN(cursor->bucket_sprite, (sfVector2f){0, 32});
}

static void init_colorsheet(colorsheet_t *sheet)
{
    sheet->image = sfImage_createFromFile("asset/colorsheet.png");
    sheet->texture = TEXTURE_CREATE(256, 256);
    sheet->sprite = SPRITE_CREATE();
    TEXTURE_UPDATEIMAGE(sheet->texture, sheet->image, 0, 0);
    SPRITE_SETTEXTURE(sheet->sprite, sheet->texture, 0);
    sheet->rect = SPRITE_GETGBOUNDS(sheet->sprite);
    SPRITE_SETPOS(sheet->sprite, (sfVector2f){960.0f - sheet->rect.width,
    540.0f - sheet->rect.height});
    SPRITE_SETSCALE(sheet->sprite, (sfVector2f){2.0f, 2.0f});
}

static void init_thickness(thickness_t *thickness)
{
    thickness->thickness = 0;
    thickness->sprite = create_sprite("asset/thickness.png",
    (sfVector2f){447.0f, 155.0f});
    SPRITE_SETSCALE(thickness->sprite.sprite, (sfVector2f){0.6f, 0.6f});
}

static void init_ctrl(ctrl_t *ctrl)
{
    ctrl->undo = malloc(sizeof(sfUint8) * (1152 * 648 * 4));
    ctrl->redo = malloc(sizeof(sfUint8) * (1152 * 648 * 4));
    ctrl->queue = malloc(sizeof(sfUint8) * (1152 * 648 * 4));
    for (int i = 0; i < (1152 * 648 * 4); i++)
        ctrl->queue[i] = 255;
}

paint_t init_paint(void)
{
    paint_t paint;

    init_cursor(&paint.cursor);
    init_tool(&paint.tool);
    init_ctrl(&paint.ctrl);
    init_canva(&paint.canva, WHITE);
    init_colorsheet(&paint.colorsheet);
    init_canva(&paint.queue, TRANSPARENT);
    init_thickness(&paint.thickness);
    init_screen(&paint.screen, &paint.gui);
    paint.buttons = init_buttons();
    paint.pressed = sfFalse;
    return paint;
}
