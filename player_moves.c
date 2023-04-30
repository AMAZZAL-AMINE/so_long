/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:04:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/04/30 17:02:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int count, int index, int is_finished)
{
	if (check_key.map[count - 1][index] == '0'
		|| check_key.map[count - 1][index] == 'C')
	{
		print_moves(p_move.move++);
		check_key.map[count - 1][index] = 'P';
		check_key.map[count][index] = '0';
		return ;
	}
	else if (check_key.map[count - 1][index] == 'E')
	{
		print_moves(p_move.move++);
		if (is_finished == true)
		{
			print_moves(p_move.move++);
			finished_game();
		}
	}
}

void	move_down(int count, int index, int is_finished)
{
	if (check_key.map[count + 1][index] == '0'
		|| check_key.map[count + 1][index] == 'C')
	{
		print_moves(p_move.move++);
		check_key.map[count + 1][index] = 'P';
		check_key.map[count][index] = '0';
		return ;
	}
	else if (check_key.map[count + 1][index] == 'E')
	{
		if (is_finished == true)
		{
			print_moves(p_move.move++);
			finished_game();
		}
	}
}

void	move_to_left(int count, int index, int is_finished)
{
	if (check_key.map[count][index - 1] == '0'
		|| check_key.map[count][index - 1] == 'C')
	{
		print_moves(p_move.move++);
		check_key.map[count][index - 1] = 'P';
		check_key.map[count][index] = '0';
		return ;
	}
	else if (check_key.map[count][index - 1] == 'E')
	{
		if (is_finished == true)
		{
			print_moves(p_move.move++);
			finished_game();
		}
	}
}

void	move_to_right(int count, int index, int is_finished)
{
	int	firat_move;

	firat_move = 1;
	if (check_key.map[count][index + 1] == '0'
		|| check_key.map[count][index + 1] == 'C')
	{
		print_moves(p_move.move++);
		check_key.map[count][index + 1] = 'P';
		check_key.map[count][index] = '0';
		return ;
	}
	else if (check_key.map[count][index + 1] == 'E')
	{
		if (is_finished == true)
		{
			print_moves(p_move.move++);
			finished_game();
		}
	}
}

void	player_move(int key, int is_finished)
{
	int	count;
	int	index;

	count = 0;
	while (check_key.map[count])
	{
		index = 0;
		while (check_key.map[count][index])
		{
			if (check_key.map[count][index] == 'P')
			{
				if (key == 126)
					move_up(count, index, is_finished);
				else if (key == 125)
					move_down(count, index, is_finished);
				else if (key == 123)
					move_to_left(count, index, is_finished);
				else if (key == 124)
					move_to_right(count, index, is_finished);
				return ;
			}
			index++;
		}
		count++;
	}
}
