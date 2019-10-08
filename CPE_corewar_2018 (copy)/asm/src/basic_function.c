/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** All the lib functions for the corewar project
*/

#include "asm.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str, int mode)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(mode, &str[i], 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (s2[i]-s1[i]);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}