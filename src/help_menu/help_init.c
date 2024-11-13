/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** help_init.c
*/

#include "my.h"
#include "paint.h"
#include "help.h"

sfTexture **help_init_textures(void)
{
    sfTexture **temp = malloc(3 * sizeof(sfTexture*));

    temp[0] = TEXTURE_CREATE_FILE("asset/help/first_page.png", NULL);
    temp[1] = TEXTURE_CREATE_FILE("asset/help/drawing_tools.png", NULL);
    temp[2] = TEXTURE_CREATE_FILE("asset/help/other_tools.png", NULL);
    return temp;
}

sfSprite **help_init_sprites(sfTexture **text)
{
    sfSprite **temp = malloc(sizeof(sfSprite *) * 4);

    for (int i = 0; i <= 2; i++) {
        temp[i] = SPRITE_CREATE();
        SPRITE_SETTEXTURE(temp[i], text[i], 0);
    }
    temp[3] = NULL;
    return temp;
}
