/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** the main.c of the project
*/

#include "asm.h"

int main(int ac, char **av, char **env)
{
    corewar_t corewar;

    if (*env == NULL)
        return 84;
    check_av(ac, av);
    my_main_file(open_file(av, &corewar), &corewar);
    return 0;
}