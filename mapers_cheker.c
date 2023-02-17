/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapers_cheker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:22 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/17 11:36:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool check_path_player(char **map)
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
				if (map[count - 1][index] == '1' && map[count + 1][index] == '1' && map[count][index + 1] == '1' && map[count][index - 1] == '1')
				{
					printf("\033[31mBruh, player Not found way):\033[0m\n");
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
					error_int_map();
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
					error_int_map();
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
				error_int_map();
		}
		else
		{
			if (ft_strlen(map[count]) != ft_strlen(map[count - 1]))
				error_int_map();
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
				error_int_map();
			index++;
		}
		index = 0;
		count++;
	}
	return (true);
}

// norm => 5 function end here

bool	check_for_door(char **map)
{
	int	count;
	int	index;
	int	check;

	check = 0;
	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'E')
				check++;
			index++;
		}
		count++;
	}
	if (check != 1)
		error_int_map();
	return (true);
}

bool	check_for_player(char **map)
{
	int	count;
	int	index;
	int	check;

	check = 0;
	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'P')
				check++;
			index++;
		}
		count++;
	}
	if (check != 1)
		error_int_map();
	return (true);
}