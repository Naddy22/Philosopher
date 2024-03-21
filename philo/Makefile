NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=thread #-fsanitize=adress

DEPS = ./inc/philo.h
MK = mkdir -p
RM = rm -rf
BIN = bin
SRC = main.c parsing.c error_free.c utils.c init.c actions.c
SDIR = ./src/

# -- COLORS -- #
BLACK=\033[0;30m# Black
RED=\033[0;31m# Red
GREEN=\033[0;32m# GREEN
YELLOW=\033[0;33m# YELLOW
BLUE=\033[0;34m# BLUE
PURPLE=\033[0;35m# PURPLE
CYAN=\033[0;36m# CYAN
WHITE=\033[0m# WHITE

_OBJ = $(SRC:.c=.o) #les .c sont lu en .o

OBJ= $(addprefix $(BIN)/, $(_OBJ))

all: $(NAME)

$(NAME): $(BIN) $(OBJ) # $@ prends la target et $^ prends la dependance du dessus
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Philo compilation OK$(WHITE)"

$(BIN): #crée dossier bin
	@$(MK) $(BIN)

$(BIN)/%.o: ./src/%.c $(DEPS) # remplace les .c par .o avec -c . $< = dependance le plus a gauche
	@$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all clean fclean re #.phony dit que ca se ne sont pas des fichiers

clean:
	@$(RM) $(BIN)
	@echo "$(RED)Philo object files deleted$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Philo object files and executable deleted$(WHITE)"

re:	fclean all