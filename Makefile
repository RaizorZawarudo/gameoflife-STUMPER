##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	main.c	\
		load_file_memory.c	\
		gameoflife_init.c	\
		load_map_2d.c	\
		check_neighbours_one.c	\
		check_neighbours_two.c


NAME	=	gameoflife

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) clean

$(NAME):
	make -C ./lib/my/
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3 -Wall -Wextra -W

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all