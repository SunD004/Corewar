/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

corewar_t *convert_file_in_list(char **tab, corewar_t *list)
{
    for (int y = 0; tab[y] != NULL; y++) {
        if (tab[y] != NULL)
            add_element_list_str(&list, tab[y]);
    }
    reverse(&list);
    list = remove_useless_char(list);
    return list;
}

corewar_t *remove_useless_char(corewar_t *list)
{
    corewar_t *new_list = NULL;
    char *dest = "\0";

    while (list != NULL) {
        dest = my_strdup_space(list->str, 0, 0);
        if (dest[0] != '\n')
            add_element_list_str(&new_list, dest);
        list->str = dest;
        list = list->next;
    }
    reverse(&new_list);
    return new_list;
}

char **make_2d_tab_file(corewar_t *list)
{
    char **tab = NULL;
    char *buffer = "\0";

    while (list != NULL) {
        buffer = my_strcat(buffer, list->str);
        list = list->next;
    }
    tab = str_to_word_array(buffer, '\n', 0, 0);
    return tab;
}

void exec_instruction(char **tab, int j, corewar_t *c)
{
    (my_strcmp("live", tab[j]) == 0) ? one_parameter(tab, c, "0x01", 0) : 0;
    (my_strcmp("ld", tab[j]) == 0) ? multiple_param(tab, c, "0x02", 1) : 0;
    (my_strcmp("st", tab[j]) == 0) ? multiple_param(tab, c, "0x03", 2) : 0;
    (my_strcmp("add", tab[j]) == 0) ? multiple_param(tab, c, "0x04", 3) : 0;
    (my_strcmp("sub", tab[j]) == 0) ? multiple_param(tab, c, "0x05", 4) : 0;
    (my_strcmp("and", tab[j]) == 0) ? multiple_param(tab, c, "0x06", 5) : 0;
    (my_strcmp("or", tab[j]) == 0) ? multiple_param(tab, c, "0x07", 6) : 0;
    (my_strcmp("xor", tab[j]) == 0) ? multiple_param(tab, c, "0x08", 7) : 0;
    (my_strcmp("zjmp", tab[j]) == 0) ? one_parameter(tab, c, "0x09", 8) : 0;
    (my_strcmp("ldi", tab[j]) == 0) ? multiple_param(tab, c, "0x010", 9) : 0;
    (my_strcmp("sti", tab[j]) == 0) ? multiple_param(tab, c, "0x011", 10) : 0;
    (my_strcmp("fork", tab[j]) == 0) ? one_parameter(tab, c, "0x012", 11) : 0;
    (my_strcmp("lld", tab[j]) == 0) ? multiple_param(tab, c, "0x013", 12) : 0;
    (my_strcmp("lldi", tab[j]) == 0) ? multiple_param(tab, c, "0x014", 13) : 0;
    (my_strcmp("lfork", tab[j]) == 0) ? one_parameter(tab, c, "0x015", 14) : 0;
    (my_strcmp("aff", tab[j]) == 0) ? one_parameter(tab, c, "0x10", 15) : 0;
}