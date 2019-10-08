/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

void lets_go_parse(corewar_t *corewar)
{
    corewar_t *label_list = NULL;

    for (int y = 0; corewar->file[y] != NULL; y++) {
        label_list = check_if_its_a_label(corewar->file[y], y, 0, 0);
        lets_convert(corewar->file[y], corewar);
    }
}

void lets_convert(char *str, corewar_t *corewar)
{
    char **tab = clean_my_line(str);
    int label;

    if (str[0] == '\0' || my_strlen(str) == 2)
        return;

    for (int j = 0; tab[j] != NULL; j++)
        return lets_convert_loop(tab, j, label, corewar);
}

void lets_convert_loop(char **tab, int j, int label, corewar_t *corewar)
{
    label = its_a_label(tab[j], tab, j, corewar);

    if (label == 0) {
        corewar->buffer = concat_string(corewar->buffer, corewar->label);
        corewar->buffer = concat_string(corewar->buffer, " ");
        tab[j][0] = '\0';
        if (tab[j+1] == NULL)
            return;
        exec_instruction(tab, j += 1, corewar);
        return;
    }
    if (label == 42) {
        exec_instruction(tab, j, corewar);
        return;
    }
    if (label == 1) {
        my_putstr(tab[j], 2);
        my_putstr(" : Error -> Bad label char\n", 2);
        exit(84);
    }
}