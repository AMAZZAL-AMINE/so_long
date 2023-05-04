/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_killers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:57 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/04 17:33:46 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_destroy(void)
{
	mlx_destroy_image(mlx_data.mlx, mlx_data.wall);
	mlx_destroy_image(mlx_data.mlx, mlx_data.space);
	mlx_destroy_image(mlx_data.mlx, mlx_data.player);
	mlx_destroy_image(mlx_data.mlx, mlx_data.coin);
	mlx_destroy_image(mlx_data.mlx, mlx_data.close_door);
	mlx_destroy_image(mlx_data.mlx, mlx_data.open_door);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
}

void	finished_game(void)
{
	ft_putstr("\033[32mWINNER!\nWINNER!\nCHICKEN\nDINNER!\033[0m\n");
	mlx_destroy();
	free_map(check_key.map);
	exit(0);
}

int	exit_game(void)
{
	free_map(check_key.map);
	exit(0);
	return (0);
}

void	error_in_map(void)
{
	write(2, "Error\n", 6);
	free_map(check_key.map);
	exit(1);
}

int	check_line_len(char **line)
{
	int	i ;

	i = 0;
	while (line[i])
		i++;
	return (i);
}
