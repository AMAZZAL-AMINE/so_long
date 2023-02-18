/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_nearby_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:01:33 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 12:01:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		error_in_map();
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
		error_in_map();
	return (true);
}
