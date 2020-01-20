##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

MAIN	=		main.c		\

LINK_LIB	=	./lib/linked_list_library/basing_functions.c	\
				./lib/linked_list_library/create_env.c			\
				./lib/linked_list_library/find_path.c			\
				./lib/my_printf/my_putstr.c		\
				./lib/my_printf/my_putchar.c	\
				./lib/my_printf/my_put_nbr.c 	\
				./lib/my_printf/my_printf.c 	\
				./lib/my_printf/my_strlen.c 	\
				./lib/my_printf/base.c 			\
				./lib/my_printf/my_revstr.c		\
				./lib/my_printf/my_getnbr.c 	\
				./lib/my_printf/funcs1.c		\
				./lib/my_printf/funcs2.c		\
				./lib/my_printf/funcs3.c 		\
				./lib/my_printf/my_strtol.c		\
				./lib/linked_list_library/cd_function.c			\
				./lib/linked_list_library/create_prompt.c		\
				./lib/linked_list_library/env_var.c				\
				./lib/linked_list_library/cont_cd.c

UNIT 	=		./tests/test.c 	\

MY 		=		./lib/my/my_str_to_word_array.c	\
				./lib/my/my_strcat.c			\
				./lib/my/my_strcmp.c			\
				./lib/my/my_strlen.c

CFLAGS	=	-g3

OBJ_LIBMY 	= $(MY:.c=.o)

OBJ_LINK	= $(LINK_LIB:.c=.o)

CC 		= gcc

NAME	=		mysh

LIBMY	=		./lib/my/libmy.a

LIST	=		./lib/linked_list_library/liblist.a

all:	$(OBJ_LIBMY) $(OBJ_LINK)
	ar rc $(LIBMY) $(OBJ_LIBMY)
	ar rc $(LIST) $(OBJ_LINK) $(OBJ_LIBMY)
	$(CC) -o $(NAME) $(MAIN) $(LIBMY) $(LIST)

tests_run:
	$(CC) -o units $(SRC) $(UNIT) --coverage -lcriterion ./lib/my/libmy.a

clean:
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf ./lib/my/*.o
		rm -rf ./lib/linked_list_library/*.o
		rm -rf ./lib/my_printf/*.o
		rm -rf *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBMY)
		rm -f $(LIST)
		rm -f units

re: 	fclean all