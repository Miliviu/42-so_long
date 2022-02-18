/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:29:06 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:16:41 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}

t_image	ft_create_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_program	init_map_aux(t_point point, t_program program)
{
	if (point.type == '1')
		program.sprite = ft_create_sprite(program.mlx, WALL);
	else if (point.type == '0')
		program.sprite = ft_create_sprite(program.mlx, TILE);
	else if (point.type == 'C')
		program.sprite = ft_create_sprite(program.mlx, COIN);
	else if (point.type == 'E')
		program.sprite = ft_create_sprite(program.mlx, EXIT);
	if (point.type == 'P')
		program.sprite = ft_create_sprite(program.mlx, TILE);
	if (point.type == 'X')
		program.sprite = ft_create_sprite(program.mlx, ENEMY);
	program.sprite_position.x = point.x * 32;
	program.sprite_position.y = point.y * 32;
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x,
		program.sprite_position.y);
	return (program);
}

void	init_map(t_program program, t_point *point)
{
	int	counter;

	counter = 0;
	mlx_clear_window(program.mlx, program.window.reference);
	while (point[counter].toggle == 1)
	{
		program = init_map_aux(point[counter], program);
		counter++;
	}
	counter = 0;
}

t_program	init_player(t_program program)
{
	int		c;	
	t_image	imgplayer;

	c = 0;
	while (program.point[c].toggle == 1)
	{
		if (program.point[c].type == 'P')
		{
			program.player.x = program.point[c].x;
			program.player.y = program.point[c].y;
			program.player.toggle = 1;
			imgplayer = ft_create_sprite(program.mlx, PLAYER);
			program.player.x *= 32;
			program.player.y *= 32;
			mlx_put_image_to_window(program.mlx, program.window.reference,
				imgplayer.reference, program.player.x, program.player.y);
		}
		c++;
	}
	return (program);
}
