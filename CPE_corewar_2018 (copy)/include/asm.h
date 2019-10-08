/*
** EPITECH PROJECT, 2018
** asm.h
** File description:
** asm.h of the project
*/

#ifndef MY_H_
#define MY_H_

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"

typedef struct corewar_s
{
    int nb_label;
    int count_label;
    int len;
    int j;
    int ret;
    int diff;
    char *my_hexa;
    char **tab_end;
    char **tab_final;
    char *buf_final;
    char *label;
    char *coding_byte;
    char *buffer;
    char **file;
    char *name_of_file;
    char *str;
    char *buff_final;
    struct corewar_s *next;
} corewar_t;

/* lib functions */
int my_strlen(char const *);
void my_put_nbr(int);
void my_putchar(char);
int my_strcmp(char const *, char const *);
char *my_strdup(char *);
char *my_strdup_space(char *, int, int);
int my_strcmp_length(char *, char *, int);
void my_putstr(char *, int);
int my_getnbr(char *);
char *my_strcat(char *, char const *);
int my_strncmp(char *, char *, unsigned int);
char *convert_base(int, int);
int binary_to_dec(int);
char *my_itoc(int);
char *concat_string(char *, char *);
char *my_strcpy(char *, char const *);
char *my_strconcat(char *, char *);
char *my_revstr(char *);
char **str_to_word_array(char *, char, int, int);
int my_strncmp(char *, char *, unsigned int);
char *my_strncpy(char const *, int);

/* -h or error argument */
void help(char **);
int check_av(int , char **);

/* open file av[1] + create char** tab */
char **open_file(char **, corewar_t *);
char **open_file_two(char **, char **, char *, corewar_t *);
corewar_t *check_file(char **, corewar_t *);

/* get header information */
header_t get_comment_and_name(char **, header_t, int);
header_t get_comment(char **, int, int, header_t);
header_t get_name(char **, int, int, header_t);

/* parse file */
void my_main_file(char **, corewar_t *);
void lets_go_parse(corewar_t *);

/* create linked list with all label */
corewar_t *check_if_its_a_label(char *, int, int, int);
corewar_t *check_if_its_a_label_two(char *, corewar_t *, int);
int check_str_label(char *str);
int check_label_correct_char(char *, int);

/* clean my line and create a 2d separator = ' ' */
char **clean_my_line(char *);
int its_a_label(char *, char **, int, corewar_t *);
int its_a_label_two(int, char *, int, corewar_t *);
char *remove_my_space(char *);

/* conversion of the file */
void lets_convert(char *, corewar_t *);
void lets_convert_loop(char **, int, int, corewar_t *);

/* last step, gestion of label */
void parse_my_buffer_pos(corewar_t *, int, int, char *);
void parse_my_buffer_neg(corewar_t *, int);
void buff_final(corewar_t *);
int check_ret_value(corewar_t *, int, int, char);
char *get_correct_label(char *);
void get_len_of_tab(corewar_t *);

/* exec instruction (live,sti,and ...) */
void exec_instruction(char **, int, corewar_t *);

/* do the coding byte and do the conversion in hexa of argument */
void get_coding_byte(char **, int, corewar_t *, int);
void get_argument_value(char *, corewar_t *);

/* do instruction */
void multiple_param(char **, corewar_t *, char *, int);
void one_parameter(char **, corewar_t *, char *, int);

/* error gestion */
void check_argument_error(char **, int);
void check_instruction_error(int, char **, int);
void check_type_argument(char, char *, int);
void check_type_error(char **, char *, int, int);
/* check lenght of the coding byte */
void check_lenght_of_coding_byte(corewar_t *);

/* prepare the parsing */
corewar_t *convert_file_in_list(char **, corewar_t *);
corewar_t *remove_useless_char(corewar_t *);
char **make_2d_tab_file(corewar_t *);

/* get path file */
char *get_my_path(char *);
char *get_my_path_two(char *, int, int);

/* conversion */
void regist_er(char *, corewar_t *);
void direct(char *, corewar_t *, int);
void indirect(char *, corewar_t *, int);
void label(char *, corewar_t *, int);

/* write in the file */
void create_core_file(corewar_t *, header_t);
void write_in_file(corewar_t *, header_t, int, int);
void write_header_in_file(corewar_t *, header_t, int);

/* linked list function */
void add_element_list_str(corewar_t **, char *);
void print_list_str(corewar_t *);
void reverse(corewar_t **);

#endif