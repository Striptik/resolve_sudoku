##
## Makefile for Makefile in /home/delafo_c/rendu/sudoki-bi
## 
## Made by delafo_c
## Login   <delafo_c@epitech.net>
## 
## Started on  Fri Feb 28 23:24:11 2014 delafo_c
## Last update Sun Mar  2 20:07:00 2014 delafo_c
##

NAME		= sudoki-bi

LIB		= -lmy -L.

INC		= -Iinclude/

SRC		= src/sudokibi.c\
		src/aff.c \
		src/recup_file.c \
		src/backtracking.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd my/; make
	@echo -e "\033[32m\nCOMPILATION DES SOURCES\n\033[0m"
	cc -g -o $(NAME) $(OBJ) $(INC) $(LIB) -lncurses

clean:
	@echo -e "\033[32m\nSUPPRESSION DES .o\n\033[0m"
	rm -f $(OBJ)
	cd my/; make clean

fclean: clean
	@echo -e "\033[32m\nSUPPRESSION DU BINAIRE ET DE LA LIB\n\033[0m"
	rm -f $(NAME)
	cd my/; make fclean

re: fclean all
	cd my/; make re

.PHONY: all clean fclean re
