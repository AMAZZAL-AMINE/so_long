# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 08:37:55 by mamazzal          #+#    #+#              #
#    Updated: 2023/02/20 09:06:09 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME  = so_long.a

CFLAGS  = -Wall -Wextra -Werror

CC = cc

SRCS =	ft_putstr.c draw_map_utilis_func.c draw_map.c player_moves.c read_map.c so_long.c the_killers.c \
		handling_map_errors/check_map_squar.c handling_map_errors/map_checker_nearby_two.c \
		handling_map_errors/map_cheker_nearby.c handling_map_errors/valid_path_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS =	ft_putstr.o draw_map_utilis_func.o draw_map.o player_moves.o read_map.o so_long.o the_killers.o \
		handling_map_errors/check_map_squar.o handling_map_errors/map_checker_nearby_two.o \
		handling_map_errors/map_cheker_nearby.o handling_map_errors/valid_path_map.o gnl/get_next_line.o gnl/get_next_line_utils.o

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
re : fclean all