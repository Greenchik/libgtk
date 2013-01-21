NAME	=	gtktest
SRC	=	main.c
OBJ	=	$(SRC:.c=.o)
LDFLAGS	=	-L./src/ -lgtk `pkg-config --libs gtk+-2.0`
CC	=	gcc
CFLAGS	=	-W -Wall -Werror `pkg-config --cflags gtk+-2.0` -g3
AR	=	ar
RANLIB	=	ranlib
LIBGTK	=	src/libgtk.a

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBGTK)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBGTK):
	make -C src/

clean:
	rm -f $(OBJ)
	make -s -C src/ clean

distclean:	clean
	rm -f $(NAME)
	make -s -C src/ distclean

rebuild:	distclean all

.PHONY: all clean distclean rebuild
