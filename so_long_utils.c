/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:43:50 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/13 14:58:47 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(void)
{
	printf("Error\n");
	return (0);
}

int	player_move(int key, void *param)
{
	t_program	*program;
	static int	previus;

	program = (t_program *)param;
	if (key == UP)
		*program = move_up(*program);
	if (key == DOWN)
		*program = move_down(*program);
	if (key == LEFT)
		*program = move_left(*program);
	if (key == RIGHT)
		*program = move_right(*program);
	if (key == ESC)
		exit(0);
	if (program->moves != 0 && program->moves != previus)
	{
		printf("Move -> %d\n", program->moves);
		print_moves(*program);
	}
	previus = program->moves;
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;
	int		rtrn;

	rtrn = 0;
	tmp = 0;
	if (n == 0)
		return (0);
	while (s1[tmp] == s2[tmp] && s1[tmp] != '\0' && s2[tmp] != '\0' \
	&& n - 1 > tmp)
		tmp++;
	return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	c;
	int		d;

	c = 0;
	d = 0;
	if ((len <= 0 && *to_find == 0) || ((!*str) && *to_find <= 0))
		return ((char *)str);
	if (!*str)
		return (NULL);
	c = ft_strlen(to_find);
	while (len >= c && *str)
	{	
		if (!(ft_strncmp(str, to_find, c)))
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}

int	close_program(int keycode, t_program *program)
{
	(void)keycode;
	(void)program;
	exit(0);
	return (1);
}
