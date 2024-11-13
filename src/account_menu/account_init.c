/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** help_init.c
*/

#include "my.h"
#include "account.h"

sfTexture **account_init_textures(void)
{
    sfTexture **temp = malloc(2 * sizeof(sfTexture*));

    temp[0] = TEXTURE_CREATE_FILE("asset/account/credit.png", NULL);
    return temp;
}

sfSprite **account_init_sprites(sfTexture **text)
{
    sfSprite **temp = malloc(sizeof(sfSprite *) * 2);

    temp[0] = SPRITE_CREATE();
    SPRITE_SETTEXTURE(temp[0], text[0], 0);
    temp[1] = NULL;
    return temp;
}
