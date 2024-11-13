/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** symetry
*/

#include "my.h"
#include "paint.h"
#include "macro.h"

static void *my_memcpy(void *dest, void *src, int n)
{
    sfUint8 *c_dest = (sfUint8 *)(dest);
    sfUint8 *c_src = (sfUint8 *)(src);

    for (int i = 0; i < n; i++)
        c_dest[i] = c_src[i];
    return (void *)(c_dest);
}

static void swap_vertical(sfUint8 *pixels, sfUint8 *mirrored,
    sfVector2i pos, int width)
{
    sfUint8 temp;
    int index1 = (pos.y * width + pos.x) * 4;
    int index2 = (pos.y * width + (width - pos.x - 1)) * 4;

    for (int i = 0; i < 4; i++) {
        temp = pixels[index1 + i];
        mirrored[index1 + i] = pixels[index2 + i];
        mirrored[index2 + i] = temp;
    }
}

sfUint8* mirror_pixels_vertical(sfUint8 *pixels, int width, int height)
{
    sfUint8 *mirrored = malloc((size_t)(width * height * 4));

    if (mirrored == NULL)
        return NULL;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width / 2; x++)
            swap_vertical(pixels, mirrored, (sfVector2i){x, y}, width);
    free(pixels);
    return mirrored;
}

static void swap_horizontal(sfUint8 *mirrored, sfVector2i pos, sfVector2i size)
{
    sfUint8 temp;
    int index1 = (pos.y * size.x + pos.x) * 4;
    int index2 = ((size.y - pos.y - 1) * size.x + pos.x) * 4;

    for (int i = 0; i < 4; i++) {
        temp = mirrored[index1 + i];
        mirrored[index1 + i] = mirrored[index2 + i];
        mirrored[index2 + i] = temp;
    }
}

sfUint8* mirror_pixels_horizontal(sfUint8 *pixels, int width, int height)
{
    sfUint8 *mirrored = malloc((size_t)(width * height * 4));

    if (mirrored == NULL)
        return NULL;
    my_memcpy(mirrored, pixels, width * height * 4);
    for (int y = 0; y < height / 2; y++)
        for (int x = 0; x < width; x++)
            swap_horizontal(mirrored, (sfVector2i){x, y},
            (sfVector2i){width, height});
    free(pixels);
    return mirrored;
}

void symetry_vertical(paint_t *paint)
{
    paint->canva.pixels =
    mirror_pixels_vertical(paint->canva.pixels, 1152, 648);
    paint->queue.pixels =
    mirror_pixels_vertical(paint->queue.pixels, 1152, 648);
}

void symetry_horizontal(paint_t *paint)
{
    paint->canva.pixels =
    mirror_pixels_horizontal(paint->canva.pixels, 1152, 648);
    paint->queue.pixels =
    mirror_pixels_horizontal(paint->queue.pixels, 1152, 648);
}
