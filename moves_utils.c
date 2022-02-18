/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:07:22 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:07:22 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_program	move_up_aux(t_program program)
{
	t_image	imgplayer;

	program.player.y -= 32;
	imgplayer = ft_create_sprite(program.mlx, PLAYER);
	program.sprite = ft_create_sprite(program.mlx, TILE);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		imgplayer.reference, program.player.x, program.player.y);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.player.x, program.player.y + 32);
	program.moves += 1;
	return (program);
}

t_program	move_down_aux(t_program program)
{
	t_image	imgplayer;

	program.player.y += 32;
	imgplayer = ft_create_sprite(program.mlx, PLAYER);
	program.sprite = ft_create_sprite(program.mlx, TILE);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		imgplayer.reference, program.player.x, program.player.y);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.player.x, program.player.y - 32);
	program.moves += 1;
	return (program);
}

t_program	move_left_aux(t_program program)
{
	t_image	imgplayer;

	program.player.x -= 32;
	imgplayer = ft_create_sprite(program.mlx, PLAYER);
	program.sprite = ft_create_sprite(program.mlx, TILE);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		imgplayer.reference, program.player.x, program.player.y);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.player.x + 32, program.player.y);
	program.moves += 1;
	return (program);
}

t_program	move_right_aux(t_program program)
{
	t_image	imgplayer;

	program.player.x += 32;
	imgplayer = ft_create_sprite(program.mlx, PLAYER);
	program.sprite = ft_create_sprite(program.mlx, TILE);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		imgplayer.reference, program.player.x, program.player.y);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.player.x - 32, program.player.y);
	program.moves += 1;
	return (program);
}
