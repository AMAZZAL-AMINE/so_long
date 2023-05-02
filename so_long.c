/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:32:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/02 20:42:25 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode)
{
	check_key.key = keycode;
	if (keycode == 53)
		exit_game();
	player_move(keycode, check_key.is_finished);
	draw_map();
	return (0);
}

void	the_all_cheker_functions(void)
{
	check_path_coin(check_key.map);
	check_path_door(check_key.map);
	check_lines_map(check_key.map);
	check_for_imposter_in_map(check_key.map);
	check_for_dupli_door(check_key.map);
	check_for_dupli_player(check_key.map);
}

void	set_images_mlx(void)
{
	int	img_width;
	int	img_height;

	mlx_data.wall = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/wall2.xpm", &img_width, &img_height);
	mlx_data.space = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/space.xpm", &img_width, &img_height);
	mlx_data.player = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/player.xpm", &img_width, &img_height);
	mlx_data.coin = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/coin.xpm", &img_width, &img_height);
	mlx_data.close_door = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/close_door.xpm", &img_width, &img_height);
	mlx_data.open_door = mlx_xpm_file_to_image(mlx_data.mlx, \
		"textures/door.xpm", &img_width, &img_height);
}

void	mlx_pointers(char *file)
{
	int	width;
	int	height;

	free_map(check_key.map);
	check_key.map = trans_to_2d_dim(file);
	width = ft_strlen(check_key.map[0]) * 50;
	height = check_line_len(check_key.map) * 50;
	mlx_data.mlx = mlx_init();
	if (!mlx_data.mlx)
		exit(1);
	mlx_data.win = mlx_new_window(mlx_data.mlx, width, height, "so_long");
	if (!mlx_data.win)
		exit(1);
	set_images_mlx();
	draw_map();
	mlx_hook(mlx_data.win, 17, 0, exit_game, NULL);
}

int	main(int argc, char **argv)
{
	char	*file;
	//todo : check size of window and conpare it with the size of screen
	if (argc != 2)
		error_in_map();
	file = argv[1];
	check_file_name(argv[1] + (ft_strlen(argv[1]) - 4));
	check_key.map = trans_to_2d_dim(file);
	check_map_content(check_key.map);
	the_all_cheker_functions();
	the_path_final_search();
	mlx_pointers(file);
	if (!mlx_data.wall || !mlx_data.space || !mlx_data.player || \
		!mlx_data.coin || !mlx_data.close_door || !mlx_data.open_door)
		error_in_map();
	mlx_key_hook(mlx_data.win, key_press, NULL);
	mlx_loop(mlx_data.mlx);
	return (0);
}
