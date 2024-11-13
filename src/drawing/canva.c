/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** queue
*/

#include "my.h"
#include "paint.h"

void reset_canva(sfUint8 *pixels)
{
    for (int i = 0; i < (1152 * 648 * 4); i++)
        pixels[i] = 0;
}

void merge_layers(sfUint8 *canva, sfUint8 *queue)
{
    for (int i = 0; i < (1152 * 648 * 4); i += 4) {
        if (queue[i + 3] != 0) {
            canva[i + 0] = queue[i + 0];
            canva[i + 1] = queue[i + 1];
            canva[i + 2] = queue[i + 2];
            canva[i + 3] = queue[i + 3];
        }
    }
}

sfBool is_same_canva(sfUint8 *c1, sfUint8 *c2)
{
    for (int i = 0; i < (1152 * 648 * 4); i++)
        if (c1[i] != c2[i])
            return FALSE;
    return TRUE;
}

void cpy_canva(sfUint8 *dest, sfUint8 *src)
{
    for (int i = 0; i < (1152 * 648 * 4); i++)
        dest[i] = src[i];
}
