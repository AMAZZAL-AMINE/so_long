
NAME  = minitalk.a

CFLAGS  = -Wall -Wextra -Werror -Imlx -c

CC = cc

SRCS =	server.c clients.c

OBJS =	server.o clients.o

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $<

clean : 
	rm -f (OBJS)

fclean : 
	rm -f $(NAME)

re : fclean all