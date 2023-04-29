/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/04/29 15:46:56 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_file_name(char *file)
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
		error_in_map();
	}
}
