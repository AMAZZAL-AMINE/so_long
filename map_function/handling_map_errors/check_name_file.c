/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/03 15:32:52 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_file_name(char *type)
{
	if (type[0] != '.' || type[1] != 'b'
		|| type[2] != 'e' || type[3] != 'r')
	{
		error_in_map();
	}
}
