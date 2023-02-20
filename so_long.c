/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:32:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 18:52:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode)
{
	check_key.key = keycode;
	if (keycode == 53)
		exit_game();
	player_move(check_key.map, keycode, check_key.is_finished);
	draw_map();
	return (0);
}

void	the_all_cheker_functions(void)
{
	char	**s;

	check_path_player(check_key.map);
	check_path_coing(check_key.map);
	check_path_door(check_key.map);
	check_lines_map(check_key.map);
	check_for_imposter_in_map(check_key.map);
	check_for_door(check_key.map);
	check_for_player(check_key.map);
	s = check_path(check_key.map);
}

void	mlx_pointers(void)
{
	int	img_width;
	int	img_height;
	int	width;
	int	height;

	width = ft_strlen(check_key.map[0]) * 50;
	height = check_line_len(check_key.map) * 50;
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, width, height, "so_long");
	mlx_data.wall = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/wall2.xpm", &img_width, &img_height);
	mlx_data.space = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/space.xpm", &img_width, &img_height);
	mlx_data.player = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/player.xpm", &img_width, &img_height);
	mlx_data.coin = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/coin.xpm", &img_width, &img_height);
	mlx_data.close_door = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/close_door.xpm", &img_width, &img_height);
	mlx_data.open_door = mlx_xpm_file_to_image(mlx_data.mlx, \
		"img/door.xpm", &img_width, &img_height);
	draw_map();
	mlx_hook(mlx_data.win, 17, 0, exit_game, NULL);
}

int	main(int argc, char **argv)
{
	char	*file;

	file = argv[1];
	if (argc != 2)
		error_in_map();
	check_key.map = trans_to_2d_dim(file);
	check_map(check_key.map);
	the_all_cheker_functions();
	the_path_final_search();
	check_key.map = trans_to_2d_dim(file);
	mlx_pointers();
	mlx_key_hook(mlx_data.win, key_press, NULL);
	mlx_loop(mlx_data.mlx);
	return (0);
}
