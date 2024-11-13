/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** parser
*/

#include "my.h"

static char **split_string(char *input, char *ptr, int count)
{
    char **numbers = malloc((size_t)((count + 1) * 8));
    int index = 0;
    char *start;
    int length;

    ptr = input;
    while (*ptr != '\0') {
        while (*ptr == ' ')
            ptr++;
        start = ptr;
        while (*ptr != ' ' && *ptr != '\0')
            ptr++;
        length = (int)(ptr - start);
        numbers[index] = malloc((size_t)(length + 1));
        my_strncpy(numbers[index], start, length);
        numbers[index][length] = '\0';
        index++;
    }
    numbers[count] = NULL;
    return numbers;
}

char **split_numbers(char *input)
{
    int count = 0;
    char *ptr = input;

    if (input[0] < '0' || input[0] > '9')
        return NULL;
    while (*ptr != '\0') {
        while (*ptr == ' ')
            ptr++;
        if (*ptr != '\0')
            count++;
        while (*ptr != ' ' && *ptr != '\0')
            ptr++;
    }
    return split_string(input, ptr, count);
}
