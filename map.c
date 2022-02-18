/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:46:04 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/13 12:43:37 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	fill_point(t_point point, char *j, int y, int i)
{
	point.toggle = 1;
	point.x = i;
	point.y = y;
	point.type = j[i];
	return (point);
}

t_point	*read_map_aux(char *path, int fd, int i, int j)
{
	static t_point	point[64800];
	int				y;
	char			*line;

	y = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
		{
			point[j] = fill_point(point[j], line, y, i);
			j++;
			i++;
		}
		i = 0;
		free(line);
		line = get_next_line(fd);
		y++;
	}	
	free(line);
	close(fd);
	return (point);
}

t_point	*read_map(char *path)
{
	return (read_map_aux(path, 0, 0, 0));
}

int	map_len(char *path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

t_vector	get_long(t_point *map)
{
	t_vector	xy;
	int			i;

	i = 0;
	while (map[i].toggle == 1)
		i++;
	xy.x = map[i - 1].x;
	xy.y = map[i - 1].y;
	return (xy);
}
