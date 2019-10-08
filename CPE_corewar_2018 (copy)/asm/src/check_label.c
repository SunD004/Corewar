/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

corewar_t *check_if_its_a_label(char *str, int line_pos, int a, int i)
{
    int save = 0;
    char *final = "\0";
    corewar_t *label_list = NULL;

    for (; str[i] != '\0'; i++)
        if (str[i] == LABEL_CHAR)
            save = i;
    if (save > 0) {
        final = malloc(sizeof(char) * save + 2);
        for (a = 0; a != save + 1; a++)
            final[a] = str[a];
        final[a] = '\0';
        if (check_str_label(final) == 1)
            return label_list;
        return check_if_its_a_label_two(final, label_list, line_pos);
    }
    return label_list;
}

corewar_t *check_if_its_a_label_two(char *final, corewar_t *label_list,
int line_pos)
{
    char *stock = concat_string(final, my_itoc(line_pos));

    add_element_list_str(&label_list, stock);
    reverse(&label_list);
    free(final);
    return label_list;
}

int check_str_label(char *str)
{
    int ok = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        ok = check_label_correct_char(str, i);
        if (ok == 1)
            return 1;
    }
    return 0;
}

int check_label_correct_char(char *str, int a)
{
    if (str[a] == LABEL_CHAR || str[a] == ' ' || str[a] == '\t')
        return 0;
    for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
        if (str[a] == LABEL_CHARS[j])
            return 0;
    }
    return 1;
}
