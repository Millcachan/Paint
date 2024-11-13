/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-titouan.pradoura
** File description:
** display_help.c
*/

#include "my.h"
#include "paint.h"
#include "help.h"

static void free_help(sfTexture **text, sfSprite **sprites)
{
    for (int i = 0; i < 3; i++) {
        free(text[i]);
        free(sprites[i]);
    }
    free(sprites);
    free(text);
}

void help_windows(void)
{
    sfEvent event;
    sfVideoMode mode = {720, 720, 32};
    sfRenderWindow *window = WINDOW_CREATE(mode, "Help", sfClose, NULL);
    sfTexture **textures = help_init_textures();
    sfSprite **sprites = help_init_sprites(textures);
    int i = 0;

    WINDOW_FRAMELIMIT(window, 60);
    if (!window)
        return;
    while (IS_OPEN(window)) {
        CLEAR(window, sfBlack);
        while (POLL_EVENT(window, &event))
            help_events(&event, window, &i);
        if (i <= 2)
            SPRITE_DRAW(window, sprites[i], 0);
        DISPLAY(window);
    }
    free_help(textures, sprites);
    WINDOW_DESTROY(window);
}

void display_help(paint_t *paint)
{
    static int first = 1;
    static sfClock *clock;
    sfTime elapsed;

    if (!paint)
        return;
    if (first == 1) {
        clock = CLOCK_CREATE();
        first = 0;
        help_windows();
        CLOCK_RESTART(clock);
    } else {
        elapsed = CLOCK_TIME(clock);
        if (sfTime_asSeconds(elapsed) < 0.5) {
            CLOCK_RESTART(clock);
            return;
        }
        help_windows();
        CLOCK_RESTART(clock);
    }
}
