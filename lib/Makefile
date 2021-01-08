##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##


CC	=	@ gcc

SRC	=	$(wildcard my/*.c) 		\
		$(wildcard printf/*.c)

OBJ	= $(SRC:.c=.o)

LIB	=	libmy.a

INC = 	../include/int_list.h ../include/my_printf.h ../include/my.h

# CFLAGS = -W -Wall -Wextra -Wno -unused-parameter

all:	$(LIB)

$(LIB):	$(OBJ)
		@ ar rsc $(LIB) $(OBJ)
		@ mkdir -p ../include/
		@ cp include/*.h ../include/
		@ echo "\033[1;36m[LIB COMPILED]\033[0m"

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(LIB)
	@ rm -f $(INC)

re:	fclean all