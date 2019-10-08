/*
** EPITECH PROJECT, 2018
** and.c
** File description:
** the and.c of the project
*/

#include "asm.h"

void check_argument_error(char **tab, int who_i_am)
{
    int arg = 0;
    int pos = 1;
    int arg_pos = 0;

    for (; tab[pos - 1][0] == '\0'; pos++);
    arg_pos = pos;
    for (; tab[arg_pos] != NULL; arg_pos++) {
        if (tab[arg_pos][0] != '\0') {
            arg++;
        }
    }
    if (arg != op_tab[who_i_am].nbr_args) {
        my_putstr(op_tab[who_i_am].mnemonique, 2);
        my_putstr(": Error -> Too much OR To few argument ", 2);
        my_putstr("in this instruction\n", 2);
        exit(84);
    }
    return check_instruction_error(who_i_am, tab, pos);
}

void check_instruction_error(int who_i_am, char **tab, int pos)
{
    (who_i_am == 0) ? check_type_error(tab, "d", who_i_am, pos) : 0;
    (who_i_am == 1) ? check_type_error(tab, "di r", who_i_am, pos) : 0;
    (who_i_am == 2) ? check_type_error(tab, "r ir", who_i_am, pos) : 0;
    (who_i_am == 3) ? check_type_error(tab, "r r r", who_i_am, pos) : 0;
    (who_i_am == 4) ? check_type_error(tab, "r r r", who_i_am, pos) : 0;
    (who_i_am == 5) ? check_type_error(tab, "rdi rid r", who_i_am, pos) : 0;
    (who_i_am == 6) ? check_type_error(tab, "rid rid r", who_i_am, pos) : 0;
    (who_i_am == 7) ? check_type_error(tab, "rid rid r", who_i_am, pos) : 0;
    (who_i_am == 8) ? check_type_error(tab, "d", who_i_am, pos) : 0;
    (who_i_am == 9) ? check_type_error(tab, "rdi dr r", who_i_am, pos) : 0;
    (who_i_am == 10) ? check_type_error(tab, "r rdi dr", who_i_am, pos) : 0;
    (who_i_am == 11) ? check_type_error(tab, "d", who_i_am, pos) : 0;
    (who_i_am == 12) ? check_type_error(tab, "di r", who_i_am, pos) : 0;
    (who_i_am == 13) ? check_type_error(tab, "rdi dr r", who_i_am, pos) : 0;
    (who_i_am == 14) ? check_type_error(tab, "d", who_i_am, pos) : 0;
    (who_i_am == 15) ? check_type_error(tab, "r", who_i_am, pos) : 0;
}

void check_type_error(char **tab, char *buf_type, int who_i_am, int pos)
{
    char **type_tab = str_to_word_array(buf_type, ' ', 0, 0);

    for (int i = 0; tab[pos] != NULL && type_tab[i] != NULL; i++) {
        check_type_argument(tab[pos][0], type_tab[i], who_i_am);
        pos++;
    }
}

void check_type_argument(char char_type, char *arg, int who_i_am)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == 'd' && char_type == '%')
            return;
        if (arg[i] == 'i' && (char_type >= '0' && char_type <= '9'))
            return;
        if (arg[i] == char_type)
            return;
    }
    my_putstr(op_tab[who_i_am].mnemonique, 2);
    my_putstr(": Error -> Wrong arguments in this instruction.\n", 2);
    exit(84);
}
