/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

char *get_my_path(char *str)
{
    int a = 0;
    int b = 0;
    int slash = 0;
    int point = 0;

    for (; str[a] != '\0'; a++) {
        if (str[a] == '/')
            slash = a;
        if (str[a] == '.')
            point = a;
    }
    return get_my_path_two(str, slash, point);
}

char *get_my_path_two(char *str, int slash, int point)
{
    char *final = malloc(my_strlen(str));
    int b = 0;

    if (slash > 0) {
        slash++;
        for (; slash != point; slash++) {
            final[b] = str[slash];
            b++;
        }
        final[b] = '\0';
        return final;
    } else {
        for (int i = 0; i != point; i++) {
            final[b] = str[i];
            b++;
        }
        final[b] = '\0';
        return final;
    }
}