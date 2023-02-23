/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_dupli_component.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:01:33 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/23 10:26:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	check_for_dupli_door(char **map)
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

bool	check_for_dupli_player(char **map)
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
