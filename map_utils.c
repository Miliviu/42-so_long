/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:23:11 by juhagon           #+#    #+#             */
/*   Updated: 2022/01/25 13:13:54 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_program program)
{
	t_image	image;
	char	*i;

	i = ft_itoa(program.moves);
	image = ft_create_sprite(program.mlx, WALL);
	mlx_string_put(program.mlx, program.window.reference, 0, 0, 0, "->");
	mlx_put_image_to_window(program.mlx, program.window.reference,
		image.reference, 32, 0);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		image.reference, 32 * 2, 0);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		image.reference, 32 * 3, 0);
	mlx_string_put(program.mlx, program.window.reference, 32, 0, 0, i);
	free(i);
}
