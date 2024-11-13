/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** help.h
*/

#include "paint.h"

#ifndef ACCOUNT_H_
    #define ACCOUNT_H_

void account_events(sfEvent *event, sfRenderWindow *window);
sfTexture **account_init_textures(void);
sfSprite **account_init_sprites(sfTexture **text);

#endif
