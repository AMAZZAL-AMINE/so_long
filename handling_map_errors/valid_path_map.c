/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:37:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 10:45:35 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_position_player(char c)
{
	if (c == '0' || c == 'C')
		return (1);
	return (0);
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
			{
				if (check_position_player(str[count + 1][index]))
				{
					str[count + 1][index] = 'P';
					count++;
				}
				if (check_position_player(str[count - 1][index]))
				{
					str[count - 1][index] = 'P';
					count--;
				}
				if (check_position_player(str[count][index + 1]))
				{
					str[count][index + 1] = 'P';
					index++;
				}
				if (check_position_player(str[count][index - 1]))
				{
					str[count][index - 1] = 'P';
					index--;
				}
			}
			index++;
		}
		count++;
	}
	return (str);
}
