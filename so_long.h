/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:49:40 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/20 17:54:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "gnl/get_next_line.h"

int		exit_game(void);
void	finished_game(void);
void	error_in_map(void);
bool	check_path_player(char **map);
bool	check_path_coing(char **map);
bool	check_path_door(char **map);
bool	check_lines_map(char **map);
void	check_map(char **map);
bool	check_for_imposter_in_map(char **map);
bool	check_for_door(char **map);
bool	check_for_player(char **map);
char	**check_path(char **str);
char	**trans_to_2d_dim(char *file);
void	player_move(char **map, int key, int is_finished);
bool	check_for_coins(void);
int		check_line_len(char **line);
void	the_path_final_search(void);
void	ft_putstr(char *str);

/**draw map function*/
void	norm_fix_wall(int a, int b);
void	norm_fix_space(int a, int b);
void	norm_fix_coin(int a, int b);
void	norm_fix_open_door(int a, int b);
void	norm_fix_close_door(int a, int b);
void	norm_fix_player(int a, int b);
void	norm_chenge_the_door(int a, int b);
void	draw_map(void);

struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*space;
	void	*player;
	void	*coin;
	void	*close_door;
	void	*open_door;
} mlx_data;

struct s_check_key
{
	int		key;
	char	**map;
	bool	is_finished;
	int		line_of_map;
} check_key;

struct s_player_moves
{
	int	moves;
} s_m;

#endif