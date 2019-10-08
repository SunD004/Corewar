/*
** EPITECH PROJECT, 2018
** linked_list.c
** File description:
** the linked_list.c of the project
*/

#include "asm.h"

void add_element_list_str(corewar_t **list, char *str)
{
    corewar_t *element = malloc(sizeof(corewar_t));
    if (!element)
        exit(EXIT_FAILURE);
    element->str = my_strdup(str);
    element->next = *list;
    *list = element;
}

void print_list_str(corewar_t *list)
{
    while (list != NULL) {
        my_putstr(list->str, 1);
        my_putchar('\n');
        list = list->next;
    }
}

void reverse(corewar_t **begin)
{
    corewar_t *list = *begin;
    corewar_t *temp = NULL;
    corewar_t *next_elem = NULL;

    while (list->next != NULL) {
        next_elem = list->next;
        list->next = temp;
        temp = list;
        list = next_elem;
    }
    list->next = temp;
    *begin = list;
}