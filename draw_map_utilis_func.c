/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utilis_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:49:32 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 13:53:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	norm_fix_wall(int a, int b)
{
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.wall, b * 50, a * 50);
}

void	norm_fix_space(int a, int b)
{
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.space, b * 50, a * 50);
}

void	norm_fix_coin(int a, int b)
{
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.space, b * 50, a * 50);
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.coin, b * 50, a * 50);
}

void	norm_fix_open_door(int a, int b)
{
	check_key.is_finished = true;
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.space, b * 50, a * 50);
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.open_door, b * 50, a * 50);
}

void	norm_fix_close_door(int a, int b)
{
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.space, b * 50, a * 50);
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.close_door, b * 50, a * 50);
}
