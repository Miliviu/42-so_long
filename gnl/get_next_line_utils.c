/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:53:59 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/13 11:20:22 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	pos;

	pos = 0;
	if (!dest && !src)
		return (dest);
	while (pos < n)
	{
		*(unsigned char *)(dest + pos) = *(unsigned char *)(src + pos);
		pos++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*goal;
	int		len_1;
	int		len_2;
	int		len_goal;

	if (!s1 || !s2)
		return (0);
	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	len_goal = len_1 + len_2;
	goal = malloc(len_goal + 1);
	if (!goal)
		return (0);
	ft_memcpy(goal, s1, len_1);
	ft_memcpy(goal + len_1, s2, len_2);
	goal[len_goal] = '\0';
	free((void *)s1);
	return (goal);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*goal;

	len = ft_strlen(src);
	goal = malloc(len + 1);
	if (!goal)
		return (0);
	ft_memcpy(goal, src, len + 1);
	return (goal);
}
