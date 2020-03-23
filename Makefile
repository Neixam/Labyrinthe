violet			=	\033[0;35m
cyan			=	\033[0;36m
vert			=	\033[0;32m
neutre			=	\033[0m
rouge			=	\033[31m

CC				=	gcc

CFLAGS			=	-Wall		\
					-ansi		\
					-pedantic	\

#LDFLAGS			=	-lMLV		\

EXEC			=	labyrinthe

SRC				=	main.c			\
					init.c			\
					parseur.c		\
					genere.c		\
					affiche_ascii.c	\
					affiche_err.c	\
					alea.c			\

HEADER			=	$(shell find includes -type f)

INC_PATH		=	$(shell find includes -type d)

OBJ_PATH		=	obj/
	
OBJ				=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

SRC_PATH		=	$(shell find src -type d)

vpath %.c $(foreach rep, $(SRC_PATH), $(rep):)

all 			:	$(EXEC)

$(EXEC)			:	$(OBJ)
	@echo "${violet}Compilation $@ ...${neutre}\c"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo " ${vert}FIN${neutre}"

$(OBJ_PATH)%.o	:	%.c $(HEADER)
	@echo "${cyan}Compilation $@ ...${neutre}\c"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	@echo " ${vert}FIN${neutre}"

clean			:
	@echo "${rouge}Suppression des objets...${neutre}"
	@/bin/rm -rf $(OBJ)
	@echo "${vert}FIN${neutre}"

bclean			:
	@echo "${rouge}Suppression de l'exécutable...${neutre}"
	@/bin/rm -rf $(EXEC)
	@echo "${vert}FIN${neutre}"

fclean			:	clean bclean

re				:	fclean all
