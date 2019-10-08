/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

void buff_final(corewar_t *corewar)
{
    for (int a = 0; corewar->tab_end[a] != NULL; a++) {
        if (corewar->tab_end[a][0] != 'L') {
        corewar->buf_final =
        concat_string(corewar->buf_final, corewar->tab_end[a]);
        corewar->buf_final = concat_string(corewar->buf_final, " ");
        }
    }
}

void parse_my_buffer_pos(corewar_t *corewar, int a, int pos, char *my_label)
{
    corewar->diff = 0;
    corewar->ret = 42;

    for (a; corewar->tab_end[a] != NULL; a++) {
        if (corewar->tab_end[a][0] == DIRECT_CHAR
            && corewar->tab_end[a][1] == LABEL_CHAR) {
            my_label = get_correct_label(corewar->tab_end[a]);
            pos = a;
            for (int c = a; corewar->tab_end[c] != NULL; c++) {
                corewar->ret = my_strcmp(corewar->tab_end[c], my_label);
                if (check_ret_value(corewar, c, pos, '+') == 0)
                    return parse_my_buffer_pos(corewar, 0, 0, "\0");
            }
        }
    }
}

void parse_my_buffer_neg(corewar_t *corewar, int a)
{
    int pos = 0;
    char *my_label = "\0";
    corewar->diff = 0;
    corewar->my_hexa = "\0";
    corewar->ret = 42;

    if (corewar->tab_end[a] == NULL)
        return;
    for (a; a != 0; a--) {
        if (corewar->tab_end[a][0] == DIRECT_CHAR
            && corewar->tab_end[a][1] == LABEL_CHAR) {
            my_label = get_correct_label(corewar->tab_end[a]);
            pos = a;
            if (a-2 == 0)
                return;
            for (int b = a; b != 0; b--) {
                corewar->ret = my_strcmp(corewar->tab_end[b], my_label);
                if (check_ret_value(corewar, b, pos, '-') == 0)
                    return parse_my_buffer_neg(corewar, corewar->len);
            }
        }
    }
}

int check_ret_value(corewar_t *corewar, int a, int pos, char neg)
{
    if (corewar->ret != 0)
        corewar->diff++;
    if (corewar->ret == 0) {
        corewar->diff--;
        if (corewar->diff != 1)
            corewar->diff++;
        corewar->tab_end[pos] = concat_string("", "lx");
        corewar->my_hexa = convert_base(corewar->diff, 16);
        if (neg == '-') {
            corewar->tab_end[pos] = concat_string(corewar->tab_end[pos], "-");
            corewar->tab_end[pos] =
            concat_string(corewar->tab_end[pos], my_itoc(corewar->diff));
        } else {
            corewar->tab_end[pos] =
            concat_string(corewar->tab_end[pos], my_itoc(corewar->diff));
        }
        return 0;
    }
    return 1;
}

char *get_correct_label(char *str)
{
    int a = 2;
    int b = 0;
    char *label = malloc(my_strlen(str));

    for (; str[a] != '\0'; a++) {
        label[b] = str[a];
        b++;
    }
    label[b] = LABEL_CHAR;
    label[b+1] = '\0';
    return label;
}
