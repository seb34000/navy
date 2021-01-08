##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC	=	@ gcc

SRC	=	$(wildcard src/*.c) 				\
		$(wildcard src/comunication/*.c) 	\
		$(wildcard src/error/*.c) 			\
		$(wildcard src/game_loop/*.c)

OBJ	= $(SRC:.c=.o)

CLIB	=	-L ./lib/ -lmy

NOM	=	navy

CFLAGS += -I ./include/
CFLAGS += -W -Wall -Wextra

all:	$(NOM)

$(NOM):	comp $(OBJ)
	@ $(CC) $(OBJ) -o $(NOM) $(CLIB) $(CFLAGS)
	@ make clean
	@ echo "\033[1;36m[PROJECT COMPILED]\033[0m"

comp:
	@ make -C ./lib/

clean:
	@ $(RM) $(OBJ)
	@ make clean -C ./lib/

fclean: clean
	@ $(RM) $(NOM)
	@ make fclean -C ./lib/
	@ echo "\033[1;32m[CLEAN OK]\033[0m"

re:	fclean all

r:	clean $(OBJ)
	@ $(CC)  $(OBJ) -o $(NOM) $(CLIB) $(CFLAGS)
	@ make clean
	@ echo "\033[1;32m[FAST MAKE OK]\033[0m"