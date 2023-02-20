/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/20 20:40:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reada_the_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r'
		&& file[i - 2] == 'e'
		&& file[i - 3] == 'b'
		&& file[i - 4] == '.')
		return ;
	else
	{
		ft_putstr("Error: Invalid file name !\n");
		exit_game();
	}
}
