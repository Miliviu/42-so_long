/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:46:43 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/06 09:11:43 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

/*
 * This function checks for a line break in the static variable
 * if there is none it reads the file and joins the chars readed
 * (If the memory is empty, memory is alloced with ft_strdup)
 */
char	*add_line(int fd, char *memory)
{
	int		i;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(memory, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		if (!memory)
			memory = ft_strdup(buf);
		else
			memory = ft_strjoin(memory, buf);
	}
	free(buf);
	return (memory);
}

/*
 * This function checks the memory and with the len of the line
 * it appends the number of characters that the line has and then returns
 * it
 */
char	*put_line(char *memory)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	if (!memory)
		return (NULL);
	j = size_line(memory);
	rtn = (char *)malloc(sizeof(char) * (j + 1));
	if (!rtn)
		return (NULL);
	while (i < j)
	{
		rtn[i] = memory[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

/*
 * This function removes the line that the GNL will return
 *  of the static variable only leaving in the not used characters
 */
char	*store_memory(char *mem)
{
	int		i;
	int		line_len;
	int		total_len;
	char	*rtn;

	i = 0;
	line_len = size_line(mem);
	if (!mem[line_len])
	{
		free(mem);
		return (NULL);
	}
	total_len = ft_strlen(mem);
	rtn = (char *)malloc(sizeof(char) * (total_len - line_len + 1));
	if (!rtn)
		return (NULL);
	while (line_len + i < total_len)
	{
		rtn[i] = mem[i + line_len];
		i++;
	}
	rtn[i] = '\0';
	free(mem);
	return (rtn);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = add_line(fd, memory);
	if (!memory)
		return (NULL);
	next_line = put_line(memory);
	memory = store_memory(memory);
	if (ft_strlen(next_line) == 0)
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}
