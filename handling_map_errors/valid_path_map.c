/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:37:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/20 08:45:20 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_position_player(char c)
{
	if (c == '0' || c == 'C')
		return (1);
	return (0);
}

void	all_will_be_player(int count, int index, char **str)
{
	if (check_position_player(str[count + 1][index]))
		str[count + 1][index] = 'P';
	if (check_position_player(str[count - 1][index]))
		str[count - 1][index] = 'P';
	if (check_position_player(str[count][index + 1]))
		str[count][index + 1] = 'P';
	if (check_position_player(str[count][index - 1]))
		str[count][index - 1] = 'P';
}

char	**check_path(char **str)
{
	int	count;
	int	index;

	count = 0;
	while (str[count])
	{
		index = 0;
		while (str[count][index])
		{
			if (str[count][index] == 'P')
				all_will_be_player(count, index, str);
			index++;
		}
		count++;
	}
	return (str);
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

	count = 0;
	while (check_path(check_key.map)[count])
	{
		index = 0;
		while (check_path(check_key.map)[count][index])
		{
			if (check_path(check_key.map)[count][index] == '0')
			{
				if (near_door(count + 1, index, check_path(check_key.map)))
					error_in_map();
				else if (near_door(count - 1, index, check_path(check_key.map)))
					error_in_map();
				else if (near_door(count, index + 1, check_path(check_key.map)))
					error_in_map();
				else if (near_door(count, index - 1, check_path(check_key.map)))
					error_in_map();
			}
			index++;
		}
		count++;
	}
}
