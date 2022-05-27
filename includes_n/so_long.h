/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:13:26 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 15:36:03 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs_n/libft/libft.h"
# include "../minilibx/mlx.h"
# include "../utils_n/ft_printf/ft_printf.h"
# include "../utils_n/gnl/get_next_line.h"
# define SCREEN_Y 2560
# define SCREEN_X 1440
# define DIM1 60
# define DIM2 60 
# define ESC 65307
# define ENTER 13
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLAYER "./img/player2.xpm"
# define COLLECT "./img/collect.xpm"
# define EXIT "./img/exit.xpm"
# define WALL "./img/wall.xpm"
# define FLOOR "./img/floor.xpm"
# define PLAYER2 "./img/player.xpm"
# define COLLECT2 "./img/collect2.xpm"
# define EXIT2 "./img/exit2.xpm"
# define WALL2 "./img/wall2.xpm"
# define FLOOR2 "./img/floor4.xpm"
# define ENEMY "./img/enemy.xpm"
# define ENEMY2 "./img/enemy2.xpm"
# define T 0xFF000000
# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

typedef struct s_img
{
	void	*player;
	void	*player2;
	void	*collect;
	void	*collect2;
	void	*exit;
	void	*exit2;
	void	*wall;
	void	*wall2;
	void	*floor;
	void	*floor2;
	void	*enemy;
	void	*enemy2;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*av;
	int		height;
	int		width;
	int		player;
	int		collect;
	int		exit;
	int		steps;
	int		end;
	int		trip;
	int		y;
	int		x;
	int		enemy;
	int		life;
	t_img	*img;
}	t_game;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		open_fd(char **av);
int		ft_parsing(char *tab, int i, int height, int width);
int		check_args(int ac, char **av);
int		ft_close(t_game *game);
int		ft_get_moves(int keypress, t_game *game);
int		left_move(t_game *game);
int		right_move(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		ft_init_img(t_game *game);
int		ft_exit(t_game *game);
int		ft_mlx(t_game *game);
int		ft_init_game(t_game *game, char *av);
int		get_height(int fd, t_game *game);
int		short_map(t_game *game);
int		is_elem(char c);
void	ft_counter(t_game *game);
void	free_game(t_game *game);
void	check_elem(t_game *game, char *tab, int i);
void	ft_create(t_game *game);
void	ft_collect(t_game *game, char c, char key);
void	ft_enemy(t_game *game);
void	open_map(t_game *game);
void	ft_init(char *av, t_game *game, int fd);

#endif
