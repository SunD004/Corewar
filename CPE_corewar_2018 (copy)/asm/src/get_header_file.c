/*
** EPITECH PROJECT, 2018
** get_header.c
** File description:
** the get_header.c of the project
*/

#include "asm.h"

header_t get_comment_and_name(char **tab, header_t header, int j)
{
    int i = 0;

    for (; tab[i] != NULL; i++) {
        header = get_name(tab, i, 0, header);
        header = get_comment(tab, i, 0, header);
    }
    return header;
}

header_t get_name(char **tab, int c, int a, header_t header)
{
    char *str = "\0";
    char *final = "\0";
    int j = 0;

    if (tab[c][0] == '.' && tab[c][1] == 'n') {
        str = my_strdup(tab[c]);
        final = malloc(sizeof(char) * my_strlen(str));
        for (int i = 7; str[i] != 34; i++) {
            final[j] = str[i];
            j++;
        }
        final[j] = '\0';
        if (my_strlen(final) > PROG_NAME_LENGTH)
            return header;
        for (a = 0; a != my_strlen(final); a++)
            header.prog_name[a] = final[a];
        header.prog_name[a] = '\0';
        free(str);
    }
    return header;
}

header_t get_comment(char **tab, int c, int a, header_t header)
{
    char *str = "\0";
    char *final = "\0";
    int j = 0;

    if (tab[c][0] == '.' && tab[c][1] == 'c') {
        str = my_strdup(tab[c]);
        final = malloc(sizeof(char) * my_strlen(str));
        for (int i = 10; str[i] != 34; i++) {
            final[j] = str[i];
            j++;
        }
        final[j] = '\0';
        if (my_strlen(final) > COMMENT_LENGTH)
            return header;
        for (a = 0; a != my_strlen(final); a++)
            header.comment[a] = final[a];
        header.comment[a] = '\0';
        free(str);
    }
    return header;
}