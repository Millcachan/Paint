/*
** EPITECH PROJECT, 2024
** Minishell
** File description:
** my_tablen
*/

int my_tablen(char **tab)
{
    int len = 0;

    while (tab[len])
        len++;
    return len;
}
