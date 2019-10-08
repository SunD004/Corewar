##
## EPITECH PROJECT, 2018
## MakeFile
## File description:
## Compiles
##

CC	=	gcc

SRC =	asm/src/advanced_function.c		\
		asm/src/basic_function.c		\
		asm/src/basic_functions_next.c	\
		asm/src/basic_functions_three.c	\
		asm/src/file_opening.c			\
		asm/src/get_header_file.c		\
		asm/src/help_and_check.c		\
		asm/src/linked_list.c			\
		asm/src/my_word_array.c			\
		asm/src/op.c					\
		asm/src/parse_file.c			\
		asm/src/parse_file_2.c			\
		asm/src/search_instructions.c	\
		asm/src/check_label.c			\
		asm/src/label.c					\
		asm/src/convert.c				\
		asm/src/write_file.c			\
		asm/src/write_file_function.c			\
		asm/src/instructions/coding_byte.c		\
		asm/src/instructions/do_instructions.c	\
		asm/src/instructions/function.c			\
		asm/src/instructions/error_gestion.c	\
		asm/src/instructions/conversion.c		\
		asm/src/main.c

CPPFLAGS += -I include

OBJ = $(SRC:.c=.o)

NAME = asm/asm

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

.PHONY: all clean fclean re test

.SILENT: $(OBJ)