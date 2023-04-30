/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_killers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:57 by mamazzal          #+#    #+#             */
/*   Updated: 2023/04/30 15:32:23 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finished_game(void)
{
	ft_putstr("\033[32mYOU WIN HH\033[0m\n");
	exit(0);
}

int	exit_game(void)
{
	ft_putstr("\033[31mEXIT THE GAME\033[0m\n");
	exit(0);
	return (0);
}

void	error_in_map(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	check_line_len(char **line)
{
	int	i ;

	i = 0;
	while (line[i])
		i++;
	return (i);
}
