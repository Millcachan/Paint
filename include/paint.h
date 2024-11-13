/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my
*/

#include "macro.h"
#include "button.h"
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

#ifndef MY_H_
    #define MY_H_

enum action_t {
    COLORPICKER,
    COLORSHEET,
    RECTANGLE,
    CIRCLE,
    ERASER,
    PENCIL,
    BUCKET,
    BRUSH,
    LINE
};

typedef struct ctrl_s {
    sfUint8 *queue;
    sfUint8 *undo;
    sfUint8 *redo;
} ctrl_t;

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} sprite_t;

typedef struct thickness_s {
    sprite_t sprite;
    button_t one_px;
    button_t three_px;
    button_t five_px;
    button_t eight_px;
    sfBool thickness;
} thickness_t;

typedef struct colorsheet_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect rect;
    sfImage *image;
} colorsheet_t;

typedef struct canva_s {
    sfTexture *texture;
    sfSprite *sprite;
    float rotation_x;
    float rotation_y;
    sfUint8 *pixels;
    sfVector2i pos1;
    sfVector2i pos2;
    float height;
    float width;
    float angle;
} canva_t;

typedef struct cursor_s {
    sfTexture *pencil_text;
    sfSprite *pencil_sprite;
    sfTexture *eraser_text;
    sfSprite *eraser_sprite;
    sfTexture *bucket_text;
    sfSprite *bucket_sprite;
    sfTexture *pipette_text;
    sfSprite *pipette_sprite;
} cursor_t;


typedef struct screen_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    float height;
    float width;
} screen_t;

typedef struct gui_s {
    sprite_t background;
} gui_t;

typedef struct tool_s {
    sfCircleShape *secondary_circle;
    sfCircleShape *primary_circle;
    sfColor secondary_color;
    sfColor primary_color;
    enum action_t action;
    sfBool security;
    sfColor color;
    int primary;
    int shape;
    int size;
} tool_t;

typedef struct paint_s {
    colorsheet_t colorsheet;
    thickness_t thickness;
    button_t *buttons;
    sfBool released;
    screen_t screen;
    cursor_t cursor;
    sfBool pressed;
    canva_t canva;
    canva_t queue;
    sfEvent event;
    ctrl_t ctrl;
    tool_t tool;
    gui_t gui;
} paint_t;

int my_paint(void);

#endif
