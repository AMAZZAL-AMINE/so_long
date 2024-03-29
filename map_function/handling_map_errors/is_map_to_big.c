/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_to_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/04 17:33:34 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_map_to_big(void)
{
	int	width;
	int	hight;

	width = ft_strlen(check_key.map[0]);
	hight = check_line_len(check_key.map);
	if (width > 51 || hight > 28)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
