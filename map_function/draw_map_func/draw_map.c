/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:10:15 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/21 10:40:24 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	check_for_coins(void)
{
	char	**map;
	int		count;
	int		index;
	int		chekr;

	count = 0;
	chekr = 0;
	map = check_key.map;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'C')
			{
				return (1);
			}
			index++;
		}
		count++;
	}
	return (0);
}

void	norm_fix_player(int a, int b)
{
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.space, b * 50, a * 50);
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.win, mlx_data.player, b * 50, a * 50);
}

void	norm_change_the_door(int a, int b)
{
	if (check_for_coins() == 0)
		norm_fix_open_door(a, b);
	else
		norm_fix_close_door(a, b);
}

void	draw_map(void)
{
	int	a;
	int	b;

	a = 0;
	while (check_key.map[a])
	{
		b = 0;
		while (check_key.map[a][b])
		{
			if (check_key.map[a][b] == '1')
				norm_fix_wall(a, b);
			else if (check_key.map[a][b] == '0')
				norm_fix_space(a, b);
			else if (check_key.map[a][b] == 'C')
				norm_fix_coin(a, b);
			if (check_key.map[a][b] == 'E')
				norm_change_the_door(a, b);
			if (check_key.map[a][b] == 'P')
				norm_fix_player(a, b);
			b++;
		}
		a++;
	}
}
