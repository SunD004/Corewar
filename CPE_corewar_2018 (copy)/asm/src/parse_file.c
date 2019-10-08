/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"

void init_struct(corewar_t *corewar)
{
    corewar->buffer = "\0";
    corewar->coding_byte = "\0";
    corewar->label = "\0";
    corewar->my_hexa = "\0";
    corewar->ret = 42;
    corewar->diff = 0;
    corewar->buf_final = "\0";
    corewar->len = 0;
    corewar->nb_label = 0;
}

void my_main_file(char **tab, corewar_t *corewar)
{
    corewar_t *list = NULL;
    header_t header = get_comment_and_name(tab, header, 0);

    header.magic = COREWAR_EXEC_MAGIC;
    list = convert_file_in_list(tab, list);
    corewar->file = make_2d_tab_file(list);
    init_struct(corewar);
    lets_go_parse(corewar);
    corewar->tab_end = str_to_word_array(corewar->buffer, ' ', 0, 0);
    get_len_of_tab(corewar);
    parse_my_buffer_pos(corewar, 0, 0, "\0");
    parse_my_buffer_neg(corewar, corewar->len);
    buff_final(corewar);
    create_core_file(corewar, header);
    exit(0);
}

void get_len_of_tab(corewar_t *corewar)
{
    for (corewar->len = 0; corewar->tab_end[corewar->len]; corewar->len++);

    corewar->len--;
}