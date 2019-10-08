/*
** EPITECH PROJECT, 2019
** COREWAR
** File description:
** word array for corewar
*/

#include "asm.h"

char **malloc_tab(char *buffer, char **tab, int line, char chara)
{
    int col = 0;
    int j = 0;

    for (int i = 0; buffer[i] != '\0'; i = i + 1)
        if (buffer[i] == chara)
            line = line + 1;
    tab = malloc(sizeof(char *) * (line + 2));
    tab[line + 1] = NULL;
    for (int i = 0; buffer[i] != '\0'; i = i + 1) {
        if (buffer[i] == chara) {
            tab[j] = malloc(sizeof(char) * (col + 1));
            j = j + 1;
            col = -1;
        }
        col = col + 1;
    }
    tab[j] = malloc(sizeof(char) * (col + 1));
    return (tab);
}

char **str_to_word_array(char *buffer, char chara, int j, int x)
{
    char **tab = NULL;
    int i = 0;

    tab = malloc_tab(buffer, tab, 0, chara);
    for (; buffer[i] != '\0'; i++, j++) {
        if (tab[j + 1] == NULL)
            break;
        for (; buffer[i] != chara; i++, x++)
            tab[j][x] = buffer[i];
        tab[j][x] = '\0';
        x = 0;
    }
    for (; buffer[i] != '\0'; i++, x++)
        tab[j][x] = buffer[i];
    tab[j][x] = '\0';
    return (tab);
}