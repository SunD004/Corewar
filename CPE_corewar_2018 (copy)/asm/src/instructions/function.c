/*
** EPITECH PROJECT, 2018
** and.c
** File description:
** the and.c of the project
*/

#include "asm.h"

char *get_final_str(char *arg, char *copy)
{
    char *final = "\0";
    int a = 0;

    if (arg[0] == DIRECT_CHAR || arg[0] == 'r') {
        for (int i = 1; arg[i] != '\0'; i++) {
            copy[a] = arg[i];
            a++;
        }
        copy[a] = '\0';
    } else {
        for (int i = 0; arg[i] != '\0'; i++) {
            copy[a] = arg[i];
            a++;
        }
        copy[a] = '\0';
    }
    final = copy;
    if (final[0] == '\0')
        final[0] = '0';
    return final;
}

void get_argument_value(char *arg, corewar_t *corewar)
{
    char *copy = malloc(sizeof(char) * my_strlen(arg) + 2);
    char *final = get_final_str(arg, copy);
    int a = 0;

    if (arg[0] == 'r')
        return regist_er(final, corewar);

    if (arg[0] == DIRECT_CHAR && arg[1] != LABEL_CHAR)
        return direct(final, corewar, 0);

    if (my_getnbr(final) >= 1 && my_getnbr(final) <= 255 || arg[0] == '0')
        return indirect(final, corewar, 0);

    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
        return label(arg, corewar, 0);
}