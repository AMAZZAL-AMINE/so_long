/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_squar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:18:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 11:57:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_first_line(char **map, int count, int i)
{
	(void)count;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			error_in_map();
		i++;
	}
	return (true);
}

bool	check_last_line(char **map, int count, int i)
{
	while (map[count][i])
	{
		if (map[count][i] != '1')
			error_in_map();
		i++;
	}
	return (true);
}

bool	check_middle_line(char **map, int count, int i)
{
	while (map[count][i])
	{
		if (map[count][0] != '1')
			error_in_map();
		else if (map[count][i + 1] == 0)
		{
			if (map[count][i] != '1')
				error_in_map();
		}
		i++;
	}
	return (true);
}

void	check_map(char **map)
{
	int	count;
	int	i;

	count = 0;
	while (map[count])
	{
		i = 0;
		if (count == 0)
			check_first_line(map, count, i);
		else if (map[count + 1] == 0)
			check_last_line(map, count, i);
		else
			check_middle_line(map, count, i);
		count++;
	}
}
