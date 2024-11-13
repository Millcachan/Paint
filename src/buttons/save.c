/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** save
*/

#include "my.h"
#include "paint.h"

void save(paint_t *paint)
{
    sfImage* image = sfTexture_copyToImage(paint->canva.texture);

    sfImage_saveToFile(image, "./img/image.png");
    sfImage_destroy(image);
}
