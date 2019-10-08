/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** All the function for opening files
*/

#include "asm.h"

char *my_realloc(char *buffer, int length)
{
    char *realloc_str = malloc(sizeof(char)
    * (my_strlen(buffer) + length + 1));

    for (int i = 0; buffer[i] != '\0'; i = i + 1)
        realloc_str[i] = buffer[i];
    realloc_str[my_strlen(buffer) + length] = '\0';
    return (realloc_str);
}

char **open_file(char **av, corewar_t *corewar)
{
    char *c = malloc(sizeof(char) * 1);
    char *buffer = malloc(sizeof(char) * (1));
    char **tab = NULL;
    int fd = open(av[1], O_RDONLY);
    int read_value = -1;
    int i = 0;

    if (fd == -1) {
        my_putstr("Error: File doesn't exist\n", 2);
        exit(84);
    }
    buffer[0] = '\0';
    for (; read_value != 0; i = i + 1) {
        read_value = read(fd, c, 1);
        buffer = my_realloc(buffer, 1);
        buffer[i] = c[0];
    }
    buffer[i - 1] = '\0';
    return open_file_two(av, tab, buffer, corewar);
}

char **open_file_two(char **av, char **tab, char *buffer, corewar_t *corewar)
{
    corewar->name_of_file = av[1];
    tab = str_to_word_array(buffer, '\n', 0, 0);
    free(buffer);
    return tab;
}