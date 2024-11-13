/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_

    // Defines for usage
    #define TRUE 1
    #define FALSE 0
    #define HELP 42
    #define ERROR 84
    #define WHITE 255
    #define SUCCESS 0
    #define TRANSPARENT 0

    // Defines for window
    #define CLEAR sfRenderWindow_clear
    #define CLOSE sfRenderWindow_close
    #define IS_OPEN sfRenderWindow_isOpen
    #define DISPLAY sfRenderWindow_display
    #define POLL_EVENT sfRenderWindow_pollEvent
    #define WINDOW_CREATE sfRenderWindow_create
    #define WINDOW_DESTROY sfRenderWindow_destroy
    #define WINDOW_FRAMELIMIT sfRenderWindow_setFramerateLimit

    // Defines for the clock
    #define CLOCK_CREATE sfClock_create
    #define CLOCK_RESTART sfClock_restart
    #define CLOCK_TIME sfClock_getElapsedTime

    // Defines for rectangles shapes
    #define RECTANGLE_CREATE sfRectangleShape_create
    #define RECTANGLE_SETSIZE sfRectangleShape_setSize
    #define RECTANGLE_DESTROY sfRectangleShape_destroy
    #define RECTANGLE_SETSCALE sfRectangleShape_setScale
    #define RECTANGLE_SETPOS sfRectangleShape_setPosition
    #define RECTANGLE_SETORIGIN sfRectangleShape_setOrigin
    #define RECTANGLE_DRAW sfRenderWindow_drawRectangleShape
    #define RECTANGLE_FILLCOLOR sfRectangleShape_setFillColor
    #define RECTANGLE_GETGBOUNDS sfRectangleShape_getGlobalBounds
    #define RECTANGLE_SETOUTLINECOLOR sfRectangleShape_setOutlineColor
    #define RECTANGLE_SETOUTLINETHICK sfRectangleShape_setOutlineThickness

    // Defines for Circles
    #define CIRCLE_CREATE sfCircleShape_create
    #define CIRCLE_DESTROY sfCircleShape_destroy
    #define CIRCLE_SETRAD sfCircleShape_setRadius
    #define CIRCLE_SETPOS sfCircleShape_setPosition
    #define CIRCLE_DRAW sfRenderWindow_drawCircleShape
    #define CIRCLE_SETFILLCOLOR sfCircleShape_setFillColor
    #define CIRCLE_SETOUTLINECOLOR sfCircleShape_setOutlineColor
    #define CIRCLE_SETOUTILETHICK sfCircleShape_setOutlineThickness

    // Defines for rects
    #define RECT_CONTAINS sfFloatRect_contains

    // Defines for Sprites
    #define SPRITE_CREATE sfSprite_create
    #define SPRITE_DESTROY sfSprite_destroy
    #define SPRITE_SETSCALE sfSprite_setScale
    #define SPRITE_SETPOS sfSprite_setPosition
    #define SPRITE_GETPOS sfSprite_getPosition
    #define SPRITE_SETORIGIN sfSprite_setOrigin
    #define SPRITE_SETTEXTURE sfSprite_setTexture
    #define SPRITE_DRAW sfRenderWindow_drawSprite
    #define SPRITE_SETROTATION sfSprite_setRotation
    #define SPRITE_GETGBOUNDS sfSprite_getGlobalBounds

    // Defines for Texture
    #define TEXTURE_CREATE sfTexture_create
    #define TEXTURE_CREATE_FILE sfTexture_createFromFile
    #define TEXTURE_DESTROY sfTexture_destroy
    #define TEXTURE_UPDATE sfTexture_updateFromPixels
    #define TEXTURE_UPDATEIMAGE sfTexture_updateFromImage

    // Defines for mouse
    #define MOUSE_GETPOS sfMouse_getPositionRenderWindow

    // Defines for Image
    #define IMAGE_DESTROY sfImage_destroy

    // Defines for paint
    #define SIZE paint->tool.size
    #define COLOR paint->tool.color
    #define SHAPE paint->tool.shape
    #define ACTION paint->tool.action
    #define CANVA_W paint->canva.width
    #define CANVA_H paint->canva.height
    #define SCREEN_W paint->screen.width
    #define SCREEN_H paint->screen.height
    #define KEYCODE paint->event.key.code

#endif
