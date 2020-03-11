CC		=	colorgcc

NAME	=	labyrinthe

SRC		=	src/

CNT		=	$(SRC)main.c		\
			$(SRC)parseur.c		\
			$(SRC)affiche_err	\

HEADER	=	includes/

CFLAGS	=	-Wall		\
			-ansi		\
			-pedantic	\

LDFLAGS	=	-lMLV		\

OBJ		=	$(CNT:.c=.o)

all 	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc $(CFLAGS) -o $^ $(LDFLAGS)

%.o		:	%.c
	gcc $(CFLAGS) -o $@ -c $^ -I $(HEADER)

clean	:
	/bin/rm -rf $(OBJ)

bclean	:
	/bin/rm -rf $(NAME)

fclean	:	clean bclean

re		:	fclean all
