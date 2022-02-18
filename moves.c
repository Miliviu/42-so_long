/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:45:43 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:12:50 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_program	move_up(t_program program)
{
	int		c;

	c = 0;
	while (program.point[c++].toggle == 1)
		if (program.point[c].x == program.player.x
			/ 32 && (program.player.y - 32) / 32 == program.point[c].y)
			break ;
	if (program.point[c].type == '0' || program.point[c].type == 'C'
		|| program.point[c].type == 'P')
		program = move_up_aux(program);
	if (program.point[c].type == 'C')
		program.point[c].type = '0';
	if (program.point[c].type == 'E')
		check_exit(program);
	if (program.point[c].type == 'X')
		exit(0);
	return (program);
}

t_program	move_down(t_program program)
{
	int		c;

	c = 0;
	while (program.point[c++].toggle == 1)
		if (program.point[c].x == (program.player.x / 32) && (program.player.y
				 + 32) / 32 == program.point[c].y)
			break ;
	if (program.point[c].type == '0' || program.point[c].type == 'C'
		|| program.point[c].type == 'P')
		program = move_down_aux(program);
	if (program.point[c].type == 'C')
		program.point[c].type = '0';
	if (program.point[c].type == 'E')
		check_exit(program);
	if (program.point[c].type == 'X')
		exit(0);
	return (program);
}

t_program	move_left(t_program program)
{
	int		c;

	c = 0;
	while (program.point[c++].toggle == 1)
		if (program.point[c].x == (program.player.x - 32)
			/ 32 && (program.player.y) / 32 == program.point[c].y)
			break ;
	if (program.point[c].type == '0' || program.point[c].type == 'C'
		|| program.point[c].type == 'P')
	{
		program = move_left_aux(program);
	}
	if (program.point[c].type == 'C')
		program.point[c].type = '0';
	if (program.point[c].type == 'E')
		check_exit(program);
	if (program.point[c].type == 'X')
		exit(0);
	return (program);
}

t_program	move_right(t_program program)
{
	int		c;

	c = 0;
	while (program.point[c++].toggle == 1)
		if (program.point[c].x == (program.player.x + 32)
			/ 32 && (program.player.y) / 32 == program.point[c].y)
			break ;
	if (program.point[c].type == '0' || program.point[c].type == 'C'
		|| program.point[c].type == 'P')
		program = move_right_aux(program);
	if (program.point[c].type == 'C')
		program.point[c].type = '0';
	if (program.point[c].type == 'E')
		check_exit(program);
	if (program.point[c].type == 'X')
		exit(0);
	return (program);
}

void	check_exit(t_program program)
{
	int	i;

	i = 0;
	while (program.point[i].toggle == 1)
	{
		if (program.point[i].type == 'C')
			return ;
		i++;
	}
	exit(0);
}
