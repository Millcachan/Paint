/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** help.h
*/

#include "paint.h"

#ifndef HELP_H_
    #define HELP_H_

void help_events(sfEvent *event, sfRenderWindow *window, int *i);
sfTexture **help_init_textures(void);
sfSprite **help_init_sprites(sfTexture **text);

#endif
