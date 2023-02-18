/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:04:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 17:32:58 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int count, int index, char **map, int is_finished)
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

void	move_down(int count, int index, char **map, int is_finished)
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

void	move_to_left(int count, int index, char **map, int is_finished)
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

void	move_to_right(int count, int index, char **map, int is_finished)
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
			finished_game();
	}
}

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
					move_up(count, index, map, is_finished);
				else if (key == 125)
					move_down(count, index, map, is_finished);
				else if (key == 123)
					move_to_left(count, index, map, is_finished);
				else if (key == 124)
					move_to_right(count, index, map, is_finished);
				return ;
			}
			index++;
		}
		count++;
	}
}
