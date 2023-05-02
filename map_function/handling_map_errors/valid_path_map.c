/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:37:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/02 20:29:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

struct	s_vars
{
	int	index;
	int	count;
} vars;

int	check_position_player(char c)
{
	if (c == '0' || c == 'C')
		return (1);
	return (0);
}

void	all_will_be_player(int count, int index)
{
	if (check_position_player(check_key.map[count + 1][index]))
	{
		check_key.map[count + 1][index] = 'P';
		vars.count = count + 1;
	}
	if (check_position_player(check_key.map[count - 1][index]))
	{
		check_key.map[count - 1][index] = 'P';
		vars.count = count - 1;
	}
	if (check_position_player(check_key.map[count][index + 1]))
	{
		check_key.map[count][index + 1] = 'P';
		vars.index = index + 1;
	}
	if (check_position_player(check_key.map[count][index - 1]))
	{
		check_key.map[count][index - 1] = 'P';
		vars.index = index - 1;
	}
}

char	**check_path(void)
{
	vars.count = 0;
	while (check_key.map[vars.count])
	{
		vars.index = 0;
		while (check_key.map[vars.count][vars.index])
		{
			if (check_key.map[vars.count][vars.index] == 'P')
				all_will_be_player(vars.count, vars.index);
			vars.index++;
		}
		vars.count++;
	}
	return (check_key.map);
}

int	near_door(int count, int index, char **map)
{
	if (map[count][index] == 'C' || map[count][index] == 'E')
	{
		if (map[count][index] == 'E')
		{
			if ((map[count - 1][index] == 'P')
				|| (map[count + 1][index] == 'P')
				|| (map[count][index + 1] == 'P')
				|| (map[count][index - 1] == 'P'))
			{
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

void	the_path_final_search(void)
{
	int	count;
	int	index;

	count = -1;
	while (check_path()[++count])
	{
		index = -1;
		while (check_path()[count][++index])
		{
			if (check_path()[count][index] == '0'
				|| check_path()[count][index] == 'C')
			{
				if (check_path()[count][index] == 'C')
					error_in_map();
				if (near_door(count + 1, index, check_path()))
					error_in_map();
				else if (near_door(count - 1, index, check_path()))
					error_in_map();
				else if (near_door(count, index + 1, check_path()))
					error_in_map();
				else if (near_door(count, index - 1, check_path()))
					error_in_map();
			}
		}
	}
}
