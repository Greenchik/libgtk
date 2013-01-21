NAME	=	libgtk.a
SRC	=	window.c		\
		parent.c		\
		connect_parent.c	\
		box.c			\
		button.c		\
		notebook.c		\
		textview.c		\
		entry.c			\
		chatarea.c
OBJ	=	$(SRC:.c=.o)
LDFLAGS	=	`pkg-config --libs gtk+-2.0`
CC	=	gcc
CFLAGS	=	-W -Wall -Werror `pkg-config --cflags gtk+-2.0` -g3
AR	=	ar
RANLIB	=	ranlib

all:	$(NAME)

$(NAME):	$(OBJ) $(EXEC_OBJ)
	$(AR) r $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

clean:
	rm -f $(OBJ)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all
