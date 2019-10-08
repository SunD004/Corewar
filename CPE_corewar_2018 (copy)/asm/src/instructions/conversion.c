/*
** EPITECH PROJECT, 2018
** and.c
** File description:
** the and.c of the project
*/

#include "asm.h"

void regist_er(char *final, corewar_t *corewar)
{
    if (my_strlen(final) == 2)
        corewar->buffer = concat_string(corewar->buffer, "Rx");
    if (my_strlen(final) == 1)
        corewar->buffer = concat_string(corewar->buffer, "Rx");
    corewar->buffer = concat_string(corewar->buffer, final);
    corewar->buffer = concat_string(corewar->buffer, " ");
    return;
}

void direct(char *final, corewar_t *corewar, int a)
{
    for (a = 0; a != DIR_SIZE-1; a++)
        corewar->buffer = concat_string(corewar->buffer, "Dx00 ");
    if (my_strlen(final) == 2)
        corewar->buffer = concat_string(corewar->buffer, "Dx");
    if (my_strlen(final) == 1)
        corewar->buffer = concat_string(corewar->buffer, "Dx");
    corewar->buffer = concat_string(corewar->buffer, final);
    corewar->buffer = concat_string(corewar->buffer, " ");
    return;
}

void indirect(char *final, corewar_t *corewar, int a)
{
    for (a = 0; a != IND_SIZE-1; a++)
        corewar->buffer = concat_string(corewar->buffer, "Ix00 ");
    if (my_strlen(final) == 2)
        corewar->buffer = concat_string(corewar->buffer, "Ix");
    if (my_strlen(final) == 1)
        corewar->buffer = concat_string(corewar->buffer, "Ix");
    corewar->buffer = concat_string(corewar->buffer, final);
    corewar->buffer = concat_string(corewar->buffer, " ");
    return;
}

void label(char *arg, corewar_t *corewar, int a)
{
    for (a = 0; a != T_LAB-1; a++)
        corewar->buffer = concat_string(corewar->buffer, "lx00 ");
    corewar->buffer = concat_string(corewar->buffer, arg);
    corewar->buffer = concat_string(corewar->buffer, " ");
    corewar->nb_label++;
    return;
}
