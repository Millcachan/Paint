/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** display_account.c
*/

#include "account.h"

static void free_account(sfTexture **text, sfSprite **sprites)
{
    for (int i = 0; i < 1; i++) {
        free(text[i]);
        free(sprites[i]);
    }
    free(sprites);
    free(text);
}

void account_windows(void)
{
    sfEvent event;
    sfVideoMode mode = {720, 720, 32};
    sfRenderWindow *window = WINDOW_CREATE(mode, "Help", sfClose, NULL);
    sfTexture **textures = account_init_textures();
    sfSprite **sprites = account_init_sprites(textures);

    WINDOW_FRAMELIMIT(window, 60);
    if (!window)
        return;
    while (IS_OPEN(window)) {
        CLEAR(window, sfBlack);
        while (POLL_EVENT(window, &event))
            account_events(&event, window);
        SPRITE_DRAW(window, sprites[0], 0);
        DISPLAY(window);
    }
    free_account(textures, sprites);
    WINDOW_DESTROY(window);
}

void display_account(paint_t *paint)
{
    static int first = 1;
    static sfClock *clock;
    sfTime elapsed;

    if (!paint)
        return;
    if (first == 1) {
        clock = CLOCK_CREATE();
        first = 0;
        account_windows();
        CLOCK_RESTART(clock);
    } else {
        elapsed = CLOCK_TIME(clock);
        if (sfTime_asSeconds(elapsed) < 0.5) {
            CLOCK_RESTART(clock);
            return;
        }
        account_windows();
        CLOCK_RESTART(clock);
    }
}
