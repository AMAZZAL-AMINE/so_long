/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:13:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/02/18 15:28:27 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	the_path_final_search(void)
{
	int	count;
	int	index;

	count = 0;
	while (check_path(check_key.map)[count])
	{
		index = 0;
		while (check_path(check_key.map)[count][index])
		{
			if (check_path(check_key.map)[count][index] == '0')
			{
				if (search_(count + 1, index, check_path(check_key.map)))
					error_in_map();
				else if (search_(count - 1, index, check_path(check_key.map)))
					error_in_map();
				else if (search_(count, index + 1, check_path(check_key.map)))
					error_in_map();
				else if (search_(count, index - 1, check_path(check_key.map)))
					error_in_map();
			}
			index++;
		}
		count++;
	}
}
