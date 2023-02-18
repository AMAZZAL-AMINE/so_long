/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:04:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 13:53:25 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(char **map, int key, int is_finished)
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
				if (key == 126)
				{
					if (map[count - 1][index] == '0'
						|| map[count - 1][index] == 'C')
					{
						map[count - 1][index] = 'P';
						map[count][index] = '0';
						return ;
					}
					else if (map[count - 1][index] == 'E')
					{
						if (is_finished == true)
							finished_game();
					}
				}
				else if (key == 125)
				{
					if (map[count + 1][index] == '0'
						|| map[count + 1][index] == 'C')
					{
						map[count + 1][index] = 'P';
						map[count][index] = '0';
						return ;
					}
					else if (map[count + 1][index] == 'E')
					{
						if (is_finished == true)
							finished_game();
					}
				}
				else if (key == 123)
				{
					if (map[count][index - 1] == '0'
						|| map[count][index - 1] == 'C')
					{
						map[count][index - 1] = 'P';
						map[count][index] = '0';
						return ;
					}
					else if (map[count][index - 1] == 'E')
					{
						if (is_finished == true)
							finished_game();
					}
				}
				else if (key == 124)
				{
					if (map[count][index + 1] == '0'
						|| map[count][index + 1] == 'C')
					{
						map[count][index + 1] = 'P';
						map[count][index] = '0';
						return ;
					}
					else if (map[count][index + 1] == 'E')
					{
						if (is_finished == true)
						{
							finished_game();
						}
					}
				}
			}
			index++;
		}
		count++;
	}
}
