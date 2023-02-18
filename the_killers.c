/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_killers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:57 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 13:52:35 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finished_game(void)
{
	printf("\033[32mGAME OVER\033[0m\n");
	exit(0);
}

int	exit_game(void)
{
	printf("\033[31mEXIT THE GAME\033[0m\n");
	exit(0);
	return (0);
}

void	error_in_map(void)
{
	printf("\033[31mMAP ERROR\033[0m\n");
	exit(1);
}
