/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** sprite
*/

#include "paint.h"
#include "macro.h"
#include <stdio.h>

sprite_t create_sprite(const char *path, sfVector2f pos)
{
    sprite_t sprite;

    sprite.sprite = SPRITE_CREATE();
    sprite.texture = sfTexture_createFromFile(path, NULL);
    SPRITE_SETTEXTURE(sprite.sprite, sprite.texture, sfTrue);
    SPRITE_SETPOS(sprite.sprite, pos);
    return sprite;
}
