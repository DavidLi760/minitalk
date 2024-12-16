NAME1	= client
NAME2	= server
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRC1	=	client.c
SRC2	=	server.c
OBJ1	= $(SRC1:.c=.o)
OBJ2	= $(SRC2:.c=.o)

all : $(NAME1) $(NAME2)

client : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) ft_printf/libftprintf.a -o $(NAME1)

server : $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) ft_printf/libftprintf.a -o $(NAME2)

clean :
	rm -rf $(OBJ1) $(OBJ2)

fclean : clean
	rm -rf $(NAME1) $(NAME2)

re : fclean all
	rm -rf $(OBJ1) $(OBJ2)

.PHONY : re fclean clean all
