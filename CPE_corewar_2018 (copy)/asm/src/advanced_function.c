/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** All the lib functions for the corewar project
*/

#include "asm.h"

int pos_space(char *src)
{
    int pos_space = 0;
    while (src[pos_space] == ' ' || src[pos_space] == '\t') {
        pos_space++;
    }
    return pos_space;
}

int my_strncmp(char *s1, char *s2, unsigned int len)
{
    unsigned int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < len) {
        if (s1[i] == s2[i])
            i++;
        else
            return (s1[i] - s2[i]);
    }
    return (0);
}

int my_strcmp_length(char *str, char *str_sec, int length)
{
    int i = 0;
    int x = 0;

    for (; str[i]; i = i + 1);
    if (i <= length)
        return (0);
    i = i - length;
    for (; str[i]; i = i + 1) {
        if (str[i] != str_sec[x])
            return (0);
        x = x + 1;
    }
    return (1);
}

char *my_strdup(char *src)
{
    int i = 0;
    int length = 0;
    char *dest;

    while (src[length] != 0)
        length = length + 1;
    if ((dest = malloc(length + 1)) == NULL)
        return (NULL);
    while (src[i++] != 0)
        dest[i - 1] = src[i - 1];
    dest[i - 1] = '\0';
    return (dest);
}

char *my_strdup_space(char *src, int a, int length)
{
    int i = 0;
    char *dest;

    while (src[length] != 0)
        length = length + 1;
    if ((dest = malloc(length+2)) == NULL)
        return (NULL);
    i = pos_space(src);
    while (src[i] != '\0') {
        if (src[i] == COMMENT_CHAR || src[i] == '.')
            break;
        if (src[i] != '\t') {
            dest[a] = src[i];
            a++;
        }
        i++;
    }
    dest[a] = '\n';
    dest[a + 1] = '\0';
    return (dest);
}