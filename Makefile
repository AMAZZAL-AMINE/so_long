# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 08:37:55 by mamazzal          #+#    #+#              #
#    Updated: 2023/02/20 17:53:33 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

# Compiler Flags
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = ft_putstr.c \
	   draw_map_utilis_func.c \
	   draw_map.c \
	   player_moves.c \
	   read_map.c \
	   so_long.c \
	   the_killers.c \
	   handling_map_errors/check_map_squar.c \
	   handling_map_errors/map_checker_nearby_two.c \
	   handling_map_errors/map_cheker_nearby.c \
	   handling_map_errors/valid_path_map.c \
	   gnl/get_next_line.c \
	   gnl/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(OBJS) 

# Clean target
clean:
	rm -f $(OBJS)

# Fclean target
fclean: clean
	rm -f $(NAME)

# Re target
re: fclean all