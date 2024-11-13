/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** drawing
*/

#include "paint.h"

#ifndef DRAWING_H_
    #define DRAWING_H_

void draw_line(paint_t *paint);
void bucket_fill(paint_t *paint);
void reset_canva(sfUint8 *pixels);
void draw_rectangle(paint_t *paint);
void use_colorsheet(paint_t *paint);
void use_colorpicker(paint_t *paint);
void draw_circle_shape(paint_t *paint);
void cpy_canva(sfUint8 *dest, sfUint8 *src);
void draw_canva(paint_t *paint, int is_erase);
sfBool is_same_canva(sfUint8 *c1, sfUint8 *c2);
void merge_layers(sfUint8 *canva, sfUint8 *queue);

#endif
