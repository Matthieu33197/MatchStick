##
## EPITECH PROJECT, 2019
## make
## File description:
## files
##

SRC	=	my.c				\
		print.c				\
		check.c				\
		lose.c				\
		map.c				\
		turn.c				\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
		rm -rf *.o
		rm -rf $(NAME)

fclean:		clean