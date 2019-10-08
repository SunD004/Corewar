/*
** EPITECH PROJECT, 2018
** and.c
** File description:
** the and.c of the project
*/

#include "asm.h"

void multiple_param(char **tab, corewar_t *corewar, char *hexa, int who_i_am)
{
    char *coding_byte = "\0";

    check_argument_error(tab, who_i_am);
    corewar->coding_byte = "\0";
    corewar->buffer = concat_string(corewar->buffer, hexa);
    corewar->buffer = concat_string(corewar->buffer, " ");
    for (int a = 1; tab[a] != NULL; a++) {
        if (tab[a][0] != '\0')
            get_coding_byte(tab, a, corewar, 0);
    }
    check_lenght_of_coding_byte(corewar);
    coding_byte = my_itoc(binary_to_dec(my_getnbr(corewar->coding_byte)));
    corewar->buffer = concat_string(corewar->buffer, "Cx");
    corewar->buffer = concat_string(corewar->buffer, coding_byte);
    corewar->buffer = concat_string(corewar->buffer, " ");
    for (int a = 1; tab[a] != NULL; a++) {
        if (tab[a][0] != '\0')
            get_argument_value(tab[a], corewar);
    }
}

void one_parameter(char **tab, corewar_t *corewar, char *hexa, int who_i_am)
{
    check_argument_error(tab, who_i_am);
    corewar->buffer = concat_string(corewar->buffer, hexa);
    corewar->buffer = concat_string(corewar->buffer, " ");
    for (int a = 1; tab[a] != NULL; a++) {
        if (tab[a][0] != '\0')
            get_argument_value(tab[a], corewar);
    }
}