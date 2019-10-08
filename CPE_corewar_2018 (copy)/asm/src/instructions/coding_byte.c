/*
** EPITECH PROJECT, 2018
** get_coding_byte.c
** File description:
** the get_coding_byte.c of the project
*/

#include "asm.h"

void check_lenght_of_coding_byte(corewar_t *corewar)
{
    if (my_strlen(corewar->coding_byte) == 6)
        corewar->coding_byte = concat_string(corewar->coding_byte, "00");
    if (my_strlen(corewar->coding_byte) == 4)
        corewar->coding_byte = concat_string(corewar->coding_byte, "0000");
    if (my_strlen(corewar->coding_byte) == 2)
        corewar->coding_byte = concat_string(corewar->coding_byte, "000000");
}

void get_coding_byte(char **tab, int j, corewar_t *corewar, int pos)
{
    if (tab[j+pos][0] == 'r') {
        corewar->coding_byte = concat_string(corewar->coding_byte, "01");
        return;
    }
    if (tab[j+pos][0] == DIRECT_CHAR && tab[j+pos][1] != LABEL_CHAR) {
        corewar->coding_byte = concat_string(corewar->coding_byte, "10");
        return;
    }
    if ((my_getnbr(tab[j+pos]) >= 1 && my_getnbr(tab[j+pos]) <= 255)
    || tab[j+pos][0] == '0') {
        corewar->coding_byte = concat_string(corewar->coding_byte, "11");
        return;
    }
}