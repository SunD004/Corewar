/*
** EPITECH PROJECT, 2018
** search_instructions.c
** File description:
** the search_instructions.c of the project
*/

#include "asm.h"

char **clean_my_line(char *str)
{
    int a = 0;
    char *str_final = malloc(my_strlen(str) + 2);
    char **tab = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == SEPARATOR_CHAR) {
            str_final[a] = ' ';
            a++;
        } else {
            str_final[a] = str[i];
            a++;
        }
        if ((str[i] == LABEL_CHAR && str[i+1] == ' ') || str[i+1] == '\t');
    }
    str_final[a] = '\0';
    str_final = remove_my_space(str_final);
    return tab = str_to_word_array(str_final, ' ', 0, 0);
}

char *remove_my_space(char *buffer)
{
    char *buffstock = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int i = 0;
    int i2 = 0;

    for (; buffer[i] != '\0';) {
        for (; buffer[i] == ' ' && buffer[i] != '\0'; i++);
        for (; buffer[i] != ' ' && buffer[i] != '\0'; i++) {
            buffstock[i2] = buffer[i];
            i2++;
        }
        for (; buffer[i] == ' ' && buffer[i] != '\0'; i++);
        if (buffer[i] != '\0') {
            buffstock[i2] = ' ';
            i2++;
        }
    }
    buffstock[i2] = '\0';
    return (buffstock);
}

int its_a_label(char *str, char **tab, int j, corewar_t *corewar)
{
    int save = 0;
    int i = 0;
    corewar->j = j;
    corewar->label = "\0";
    int ok = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == LABEL_CHAR)
            save = i;
    }
    if (tab[j+1] != NULL) {
        if (tab[j+1][0] == LABEL_CHAR && my_strlen(tab[j+1]) == 1) {
            save = i;
            ok = 1;
        }
    }
    if (save > 0)
        return its_a_label_two(save, str, ok, corewar);
    return 42;
}

int its_a_label_two(int save, char *str, int ok, corewar_t *corewar)
{
    int a = 0;
    int ret = 0;

    corewar->label = malloc(sizeof(char) * save + 2);
    for (a = 0; a != save + 1; a++)
        corewar->label[a] = str[a];
    if (ok == 1) {
        corewar->label[a-1] = ':';
        corewar->label[a] = '\0';
    }
    corewar->label[a] = '\0';
    ret = check_str_label(corewar->label);
    if (ret == 0 &&
        corewar->label[0] != DIRECT_CHAR && corewar->label[1] != LABEL_CHAR) {
        corewar->label = remove_my_space(corewar->label);
        return 0;
    } else if (corewar->j == 0)
        return 1;
}
