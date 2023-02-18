/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker_nearby.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:22 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 17:58:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_path_player(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'P')
			{
				if (map[count - 1][index] == '1' && map[count + 1][index] == '1'
					&& map[count][index + 1] == '1'
					&& map[count][index - 1] == '1')
				{
					ft_putstr("\033[31mBruh, player Not found way):\033[0m\n");
					exit(1);
				}
			}
			index++;
		}
		count++;
	}
	return (true);
}

bool	check_path_coing(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'C')
			{
				if (map[count - 1][index] == '1'
					&& map[count + 1][index] == '1'
					&& map[count][index + 1] == '1'
					&& map[count][index - 1] == '1')
					error_in_map();
			}
			index++;
		}
		count++;
	}
	return (true);
}

bool	check_path_door(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'E')
			{
				if (map[count - 1][index] == '1'
					&& map[count + 1][index] == '1'
					&& map[count][index + 1] == '1'
					&& map[count][index - 1] == '1')
					error_in_map();
			}
			index++;
		}
		count++;
	}
	return (true);
}

bool	check_lines_map(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		if (map[count + 1] != '\0')
		{
			if (ft_strlen(map[count]) != ft_strlen(map[count + 1]))
				error_in_map();
		}
		else
		{
			if (ft_strlen(map[count]) != ft_strlen(map[count - 1]))
				error_in_map();
		}
		count++;
	}
	return (true);
}

bool	check_for_imposter_in_map(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		while (map[count][index])
		{
			if (map[count][index] != '1'
				&& map[count][index] != '0' && map[count][index] != 'P'
				&& map[count][index] != 'C' && map[count][index] != 'E')
				error_in_map();
			index++;
		}
		index = 0;
		count++;
	}
	return (true);
}
