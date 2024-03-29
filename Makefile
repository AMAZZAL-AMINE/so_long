# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 08:37:55 by mamazzal          #+#    #+#              #
#    Updated: 2023/05/06 15:27:51 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

# Compiler Flags
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = ft_putstr.c \
	   player_moves.c \
	   read_map.c \
	   so_long.c \
	   the_killers.c \
	   print_moves.c \
	   free_map.c \
	   map_function/draw_map_func/draw_map_utilis_func.c \
	   map_function/draw_map_func/draw_map.c \
	   map_function/handling_map_errors/check_map_wall_squar.c \
	   map_function/handling_map_errors/map_checker_dupli_component.c  \
	   map_function/handling_map_errors/map_cheker_nearby.c \
	   map_function/handling_map_errors/valid_path_map.c \
	   map_function/handling_map_errors/check_name_file.c \
	   map_function/handling_map_errors/is_map_to_big.c \
	   gnl/get_next_line.c \
	   gnl/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

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