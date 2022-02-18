/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:26:10 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:38:02 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
		{
			if (line[i] != '0' && line[i] != '1'
				&& line[i] != 'C' && line[i] != 'P'
				 && line[i] != 'E' && line[i] != 'X' && line[i] != '\n')
				return (free_and_finish(line));
			i++;
		}
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (1);
}

int	free_and_finish(char *line)
{
	free(line);
	return (-1);
}

int	free_and_finish_prev(char *line, char *prev)
{
	free(prev);
	free(line);
	return (-1);
}
