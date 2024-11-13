/*
** EPITECH PROJECT, 2024
** Minishell
** File description:
** my_strcspn
*/

int my_strcspn(char *str, char c)
{
    int len = 0;

    while (str[len] != c && str[len] != '\0')
        len++;
    return len;
}
