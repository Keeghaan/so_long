/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:05:40 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:36:19 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	ft_init_img(t_game *game)
{
	int	img_height;
	int	img_width;
	int	err;

	err = 0;
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (0);
	game->img->player = mlx_xpm_file_to_image(game->mlx,
			PLAYER, &img_width, &img_height);
	game->img->collect = mlx_xpm_file_to_image(game->mlx,
			COLLECT, &img_width, &img_height);
	game->img->exit = mlx_xpm_file_to_image(game->mlx,
			EXIT, &img_width, &img_height);
	game->img->wall = mlx_xpm_file_to_image(game->mlx,
			WALL, &img_width, &img_height);
	game->img->floor = mlx_xpm_file_to_image(game->mlx,
			FLOOR, &img_width, &img_height);
	if (!game->img->player || !game->img->collect || !game->img->exit
		|| !game->img->wall || !game->img->floor)
		err++;
	if (err)
		return (ft_printf("Error\nAt least one of the xpm file is missing\n"), 0);
	return (1);
}

int	ft_init_enemy(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 0;
	img_height = 0;
	game->img->enemy = mlx_xpm_file_to_image(game->mlx,
			ENEMY, &img_width, &img_height);
	game->img->enemy2 = mlx_xpm_file_to_image(game->mlx,
			ENEMY2, &img_width, &img_height);
	if (!game->img->enemy || !game->img->enemy2)
	{
		ft_printf("Error\nThe bonus imgs arent correct\n");
		return (0);
	}
	return (1);
}

int	ft_init_trip(t_game *game)
{
	int	img_height;
	int	img_width;
	int	err;

	err = 0;
	game->img->player2 = mlx_xpm_file_to_image(game->mlx,
			PLAYER2, &img_width, &img_height);
	game->img->collect2 = mlx_xpm_file_to_image(game->mlx,
			COLLECT2, &img_width, &img_height);
	game->img->exit2 = mlx_xpm_file_to_image(game->mlx,
			EXIT2, &img_width, &img_height);
	game->img->wall2 = mlx_xpm_file_to_image(game->mlx,
			WALL2, &img_width, &img_height);
	game->img->floor2 = mlx_xpm_file_to_image(game->mlx,
			FLOOR2, &img_width, &img_height);
	if (!game->img->player2 || !game->img->collect2 || !game->img->exit2
		|| !game->img->wall2 || !game->img->floor2)
		err++;
	if (err)
		return (ft_printf("Error\nAt least one of the xpm file is missing\n"), 0);
	return (1);
}

int	ft_init_game(t_game *game, char *av)
{
	game->height = 0;
	game->width = 0;
	game->exit = 0;
	game->collect = 0;
	game->steps = 0;
	game->end = 0;
	game->trip = 0;
	game->x = 0;
	game->y = 0;
	game->player = 0;
	game->enemy = 0;
	game->life = 0;
	game->av = av;
	if (!ft_init_img(game) || !ft_init_enemy(game) || !ft_init_trip(game))
		return (0);
	game->map = NULL;
	game->win = NULL;
	return (1);
}
