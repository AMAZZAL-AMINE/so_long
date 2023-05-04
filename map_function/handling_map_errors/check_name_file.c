/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/04 15:42:56 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_file_name(char *type)
{
	if (ft_strlen(type) <= 3)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (type[0] != '.' || type[1] != 'b'
		|| type[2] != 'e' || type[3] != 'r')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
