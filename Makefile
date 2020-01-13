##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

MAIN	=		main.c		\

SRC		=		$(MAIN)

UNIT 	=		./tests/test.c 	\

CFLAGS	=	-g3

OBJ 	= $(SRC:.c=.o)

CC 		= gcc

NAME	=		mysh

LIBMY	=		./lib/my/libmy.a

all:	$(OBJ)
	$(CC) -o $(NAME) $(MAIN)

tests_run:
	$(CC) -o units $(SRC) $(UNIT) --coverage -lcriterion ./lib/my/libmy.a

clean:
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf ./lib/my/*.o
		rm -rf ./lib/ls_functions/*.o
		rm -rf *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBMY)
		rm -f units

re: 	fclean all