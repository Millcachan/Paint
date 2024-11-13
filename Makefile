##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.SILENT:

CPROG   =   $(wildcard src/*.c src/*/*.c src/*/*/*.c)

CLIB    =   $(wildcard lib/my/*.c lib/my/*/*.c)

NAME    =   my_paint

LIB     =   libmy.a

OLIB	=	$(CLIB:.c=.o)

OPROG	=	$(CPROG:.c=.o)

CFLAGS  =   -I./include -Wall -Wextra -Wconversion -pedantic

LIBFLAGS	=	-lm -L./ -lmy

CSFMLFLAGS	= 	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all: $(NAME)

$(LIB): $(OLIB)
	ar rc $(LIB) $(OLIB)

$(NAME): $(LIB) $(OPROG)
	gcc -o $(NAME) $(OPROG) $(CSFMLFLAGS) $(LIBFLAGS)
	printf "[%s] — Successfully compiled\n" $(NAME)

clean:
	rm -f $(OLIB) $(OPROG)
	rm -f coding-style-reports.log
	rm -f vgcore.*

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g

debug: re
	printf "[%s] — Debug mode enabled\n" $(NAME)

.PHONY: all clean fclean re
