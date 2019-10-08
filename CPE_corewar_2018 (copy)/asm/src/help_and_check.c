/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** the main.c of the project
*/

#include "asm.h"

void help(char **av)
{
    my_putstr("USAGE\n", 1);
    my_putstr("\t\t./asm file_name[.s]\n", 1);
    my_putstr("DESCRIPTION\n", 1);
    my_putstr("\t\tfile_name\tfile in assembly language to", 1);
    my_putstr("be converted into file_name.cor, an\n", 1);
    my_putstr("\t\t\t\texecutable in the Virtual Machine.\n", 1);
}

int check_av(int ac, char **av)
{
    if (ac > 2) {
        my_putstr("Too much argument\n", 2);
        exit(84);
    }
    for (int a = 0; av[a] != NULL; a++) {
        if (my_strcmp(av[a], "-h") == 0) {
            help(av);
            return true;
        }
    }
    return false;
}