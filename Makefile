NAME	=	labyrinthe

SRC		=	src/

CNT		=	$(SRC)main.c		\
			$(SRC)parseur.c		\
			$(SRC)affiche_err	\

HEADER	=	includes/

FLAGS	=	-Wall		\
			-ansi		\
			-pedantic	\
			-lMLV		\

OBJ		=	$(CNT:.c=.o)

all 	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc $(FLAGS) -o $^ -I $(HEADER)

%.o		:	%.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean	:
	/bin/rm -rf $(OBJ)

bclean	:
	/bin/rm -rf $(NAME)

fclean	:	clean bclean

re		:	fclean all
