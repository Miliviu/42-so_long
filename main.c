/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:21:31 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/16 09:10:10 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program		program;	
	t_vector		i;
	int				j;

	if (check_args(argc, argv[1]) == -1 || check_map(argv[1]) == -1)
		return (ft_error());
	j = 0;
	program.moves = 0;
	program.point = read_map(argv[1]);
	i = get_long(program.point);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx,
			(i.x) * 32, (i.y + 1) * 32, "so_long");
	init_map(program, program.point);
	program = init_player(program);
	mlx_key_hook(program.window.reference, *player_move, &program);
	mlx_hook(program.window.reference, 17, 0L, close_program, &program);
	mlx_loop(program.mlx);
}
