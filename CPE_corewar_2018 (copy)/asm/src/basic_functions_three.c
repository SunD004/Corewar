/*
** EPITECH PROJECT, 2019
** CPE Corewar
** File description:
** basic_functions_next
*/

#include "asm.h"

char *concat_string(char *s1, char *s2)
{
    char *s3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)) + 1);
    my_strcpy(s3, s1);
    my_strconcat(s3, s2);
    return (s3);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char const *src, int i)
{
    int size = i;
    char *dest;
    int i2 = 0;

    for (; src[size] != '\0'; size++);
    dest = malloc(sizeof(char) * (size + 1));
    for (; src[i] != '\0'; i2++) {
        dest[i2] = src[i];
        i++;
    }
    dest[i2] = '\0';
    return (dest);
}

char *my_strconcat(char *dest, char *src)
{
    int i;
    int dest_len;

    dest_len = my_strlen(dest);
    i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        ++i;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}

char *my_itoc(int nbr)
{
    int neg = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 10);

    if (nbr < 0) {
        neg = 1;
        nbr *= -1;
    }
    while (nbr > 9) {
        str[i] = (nbr % 10) + 48;
        nbr = (nbr - (nbr % 10)) / 10;
        i++;
    }
    str[i++] = nbr + 48;
    if (neg == 1)
        str[i++] = '-';
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}