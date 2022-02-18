/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:11:43 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:24:06 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_aux(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	check_limits(char *path)
{
	int		i;
	char	*line;
	char	*previus;

	previus = NULL;
	i = open(path, O_RDONLY);
	line = get_next_line(i);
	if (check_map_aux(line) == -1)
		return (free_and_finish(line));
	while (line)
	{
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			return (free_and_finish_prev(line, previus));
		free(previus);
		previus = ft_strdup(line);
		free(line);
		line = get_next_line(i);
	}
	free(line);
	if (check_map_aux(previus) == -1)
		return (free_and_finish(previus));
	free(previus);
	close(i);
	return (1);
}

int	check_bools(char *path, int i)
{
	t_bools	bools;
	char	*line;

	bools.init = 0;
	bools.fd = open(path, O_RDONLY);
	line = get_next_line(bools.fd);
	while (line)
	{
		while (line[i++])
		{
			if (line[i] == 'C')
				bools.coin = 1;
			if (line[i] == 'E')
				bools.exit = 1;
			if (line[i] == 'P')
				bools.init += 1;
		}
		i = 0;
		free(line);
		line = get_next_line(bools.fd);
	}
	free(line);
	if (bools.coin != 1 || bools.exit != 1 || bools.init != 1)
		return (free_and_finish(line));
	return (1);
}

int	check_length(char *path)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (len != ft_strlen(line))
			return (free_and_finish(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	check_map(char	*path)
{
	if (check_limits(path) == -1)
		return (-1);
	if (check_bools(path, 0) == -1)
		return (-1);
	if (check_length(path) == -1)
		return (-1);
	if (check_chars(path) == -1)
		return (-1);
	return (1);
}
