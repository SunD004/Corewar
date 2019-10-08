/*
** EPITECH PROJECT, 2018
** parse_file.c
** File description:
** the parse_file.c of the project
*/

#include "asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_core_file(corewar_t *corewar, header_t header)
{
    char *path =  concat_string("asm/", get_my_path(corewar->name_of_file));
    int fd = 0;
    int value = 0;

    if ((fd = open(my_strcat(path, ".cor"), O_WRONLY | O_CREAT
    | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
		return;
    corewar->buf_final = remove_my_space(corewar->buf_final);
    printf("%s\n", corewar->buf_final);
    corewar->tab_final = str_to_word_array(corewar->buf_final, ' ', 0, 0);
    write_in_file(corewar, header, value, fd);
}

void write_in_file(corewar_t *corewar, header_t header, int value, int fd)
{
    int zeros = 0;

    write_header_in_file(corewar, header, fd);
    for (int i = 0; corewar->tab_final[i] != NULL; i++) {
        if (corewar->tab_final[i][0] == 'I')
            i = i + 1;
        if (corewar->tab_final[i][0] == 'D')
            i = i + 3;
        if (corewar->tab_final[i][0] == 'l')
            i = i + 7;
        value = my_getnbr(my_strncpy(corewar->tab_final[i], 2));
        if (corewar->tab_final[i][0] == 'R' ||
        corewar->tab_final[i][0] == '0' || corewar->tab_final[i][0] == 'C') {
            write(fd, &value, 1);
        }
        if (corewar->tab_final[i][0] == 'I') {
            write(fd, &zeros, 1);
            write(fd, &value, 1);
        }
        if (corewar->tab_final[i][0] == 'D') {
            for (int a = 0; a != 3; a++)
                write(fd, &zeros, 1);
            write(fd, &value, 1);
        }
        if (corewar->tab_final[i][0] == 'l') {
            for (int a = 0; a != 7; a++)
                write(fd, &zeros, 1);
            write(fd, &value, 1);
        }
    }
}

void write_header_in_file(corewar_t *corewar, header_t header, int fd)
{
    int res = COMMENT_LENGTH-44;

    write(fd, &header.magic, 4);
    for (int i = 0; header.prog_name[i] != '\0'; i++)
        write(fd, &header.prog_name[i], 1);
    for (int i = 0; i != PROG_NAME_LENGTH; i++)
        write(fd, "\0", 1);
    write(fd, &header.prog_size, 4);
    for (int i = 0; header.comment[i] != '\0'; i++)
        write(fd, &header.comment[i], 1);
    for (int i = 0; i != (COMMENT_LENGTH-res); i++)
        write(fd, "\0", 1);
}