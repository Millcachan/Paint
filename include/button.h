/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** button
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

#ifndef BUTTON_H_
    #define BUTTON_H_

    #define IS_CLICKED(button, event) is_button_clicked(button, event)
    #define IS_HOVER(button, event) is_button_hover(button, event)

typedef struct paint_s paint_t;

typedef struct button_s {
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    void (*action)(paint_t *);
    sfRectangleShape *rect;
    sfFloatRect float_rect;
    sfCircleShape *circle;
    struct button_s *next;
    sfVector2f size;
    sfVector2f pos;
    sfBool active;
    float radius;
    int shape;
    int ID;
} button_t;

typedef struct stack_s {
    struct stack_s *next;
    sfVector2i pos;
} stack_t;


void red(paint_t *paint);
void undo(paint_t *paint);
void redo(paint_t *paint);
void line(paint_t *paint);
void save(paint_t *paint);
void lime(paint_t *paint);
void cyan(paint_t *paint);
void clay(paint_t *paint);
void lila(paint_t *paint);
void gold(paint_t *paint);
void blue(paint_t *paint);
void feur(paint_t *paint);
void pink(paint_t *paint);
void beige(paint_t *paint);
void white(paint_t *paint);
void brown(paint_t *paint);
void black(paint_t *paint);
void green(paint_t *paint);
void brush(paint_t *paint);
void reset(paint_t *paint);
void bucket(paint_t *paint);
void yellow(paint_t *paint);
void purple(paint_t *paint);
void orange(paint_t *paint);
void pencil(paint_t *paint);
void eraser(paint_t *paint);
void circle(paint_t *paint);
void primary(paint_t *paint);
void dark_red(paint_t *paint);
void rectangle(paint_t *paint);
void dark_blue(paint_t *paint);
void dark_gray(paint_t *paint);
void secondary(paint_t *paint);
void thickness(paint_t *paint);
void one_pixel(paint_t *paint);
void light_gray(paint_t *paint);
void exit_paint(paint_t *paint);
void colorsheet(paint_t *paint);
void five_pixel(paint_t *paint);
void three_pixel(paint_t *paint);
void eight_pixel(paint_t *paint);
void colorpicker(paint_t *paint);
void display_help(paint_t *paint);
void display_account(paint_t *paint);
void symetry_vertical(paint_t *paint);
void rotation_counter(paint_t *paint);
void symetry_horizontal(paint_t *paint);
void rotation_clockwise(paint_t *paint);

button_t *add_button(button_t *head, char *infos);
void change_active_button(paint_t *paint, sfBool active, int ID);
sfBool is_rect_button_hover(button_t *button, sfMouseMoveEvent *event);
sfBool is_circle_button_hover(button_t *button, sfMouseMoveEvent *event);
sfBool is_rect_button_clicked(button_t *button, sfMouseButtonEvent *event);
sfBool is_circle_button_clicked(button_t *button, sfMouseButtonEvent *event);

struct button_functions_s {
    int id;
    void (*function_ptr)(paint_t *);
};

static const struct button_functions_s button_function[] = {
    {0, display_help},
    {1, save},
    {2, undo},
    {3, redo},
    {4, display_account},
    {5, exit_paint},
    {6, feur},
    {7, rotation_clockwise},
    {8, rotation_counter},
    {9, symetry_horizontal},
    {10, symetry_vertical},
    {11, pencil},
    {12, eraser},
    {13, colorpicker},
    {14, bucket},
    {15, brush},
    {16, line},
    {17, circle},
    {18, rectangle},
    {19, thickness},
    {20, primary},
    {21, secondary},
    {22, black},
    {23, dark_gray},
    {24, dark_red},
    {25, red},
    {26, orange},
    {27, yellow},
    {28, green},
    {29, blue},
    {30, dark_blue},
    {31, purple},
    {32, white},
    {33, light_gray},
    {34, brown},
    {35, pink},
    {36, gold},
    {37, beige},
    {38, lime},
    {39, cyan},
    {40, clay},
    {41, lila},
    {42, colorsheet},
    {43, feur},
    {44, feur},
    {45, one_pixel},
    {46, three_pixel},
    {47, five_pixel},
    {48, eight_pixel},
    {49, reset},
    {-1, NULL}
};

#endif
