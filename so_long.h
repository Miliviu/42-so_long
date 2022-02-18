/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:29:14 by juhagon           #+#    #+#             */
/*   Updated: 2021/12/14 09:33:44 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# define WALL "sprites/wall.xpm"
# define TILE "sprites/tile1.xpm"
# define COIN "sprites/coin.xpm"
# define EXIT "sprites/exit.xpm"
# define PLAYER "sprites/player.xpm"
# define ENEMY "sprites/enemy.xpm"
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_bools
{
	short	exit;
	short	coin;
	short	init;
	int		fd;
}	t_bools;

typedef struct s_point
{
	int		x;
	int		y;
	int		toggle;
	char	type;
}			t_point;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program
{
	void				*mlx;
	int					moves;
	t_point				player;
	t_point				*point;
	t_window			window;
	t_image				sprite;
	t_vector			sprite_position;
}						t_program;

t_point		*read_map(char *path);
t_vector	get_long(t_point *map);
int			check_map(char	*path);
void		ft_move(void *param);
t_program	init_player(t_program program);
t_program	move_up(t_program program);
t_program	move_down(t_program program);
t_program	move_right(t_program program);
t_program	move_left(t_program program);
t_image		ft_create_sprite(void *mlx, char *path);
void		check_exit(t_program program);
int			ft_error(void);
int			player_move(int key, void *param);
int			map_len(char *path);
int			close_program(int keycode, t_program *program);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
int			check_args(int argc, char *argv);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
void		init_map(t_program program, t_point *point);
int			free_and_finish(char	*line);
int			free_and_finish_prev(char *line, char *prev);
char		*ft_itoa(int n);
void		print_moves(t_program program);
t_program	move_up_aux(t_program program);
t_program	move_down_aux(t_program program);
t_program	move_left_aux(t_program program);
t_program	move_right_aux(t_program program);
int			check_chars(char *path);

#endif
