/*
** EPITECH PROJECT, 2019
** CPE Corewar
** File description:
** basic_functions_next
*/

#include "asm.h"

char *my_strcat(char *dest, char const *scr)
{
    int f = 0;
    char *new = malloc(sizeof(char) *(my_strlen(dest) + my_strlen(scr) +1));
    int i = 0;

    if (scr == NULL)
        return NULL;
    for (; dest[i] != '\0'; i++)
        new[i] = dest[i];
    new[i] = '\0';
    for (; new[f] != '\0'; f = f + 1);
    for (i = 0; scr[i] != '\0'; i++) {
        new[f] = scr[i];
        f++;
    }
    new[f] = '\0';
    return new;
}

int my_getnbr(char *str)
{
    int st = 0;
    int x = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9')
            st = st * 10 + (str[x] - '0');
        else if (str[x] < '0' || str[x] > '9')
            return st;
    }
    return st;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char c;

    while (i < len / 2){
    c = *(str + i);
        *(str + i) = *(str + len - i -1);
        *(str + len - i -1) = c;
        i++;
    }
    return (str);
}

char *convert_base(int nb, int base)
{
    int size = 0;
    int nb_bis = nb;
    int i = 0;
    int chara;
    char *base_str;

    for (; nb_bis != 0; size++)
        nb_bis = nb_bis / base;
    base_str = malloc(sizeof(char) * (size + 1));
    for (; nb != 0; i++) {
        chara = (nb % base) + 48;
        if (chara > 57)
            chara = chara + 39;
        base_str[i] = chara;
        nb = nb / base;
    }
    base_str[i] = '\0';
    return (my_revstr(base_str));
}

int binary_to_dec(int num)
{
    int rem;
    int decimal_val = 0;
    int base = 1;

    while (num > 0) {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
    return (decimal_val);
}