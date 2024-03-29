/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:38:24 by mamazzal          #+#    #+#             */
/*   Updated: 2023/05/05 17:27:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**trans_to_2d_dim(char *file)
{
	int		fd;
	int		count;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	count = count_lines(file);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
