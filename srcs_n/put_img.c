/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:13:28 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:37:52 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

void	put_player_img(t_game *game, int *x, int *y)
{
	if (!game->trip)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player, (*y) * DIM1, (*x) * DIM2);
		game->x = *x;
		game->y = *y;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player2, (*y) * DIM1, (*x) * DIM2);
		game->x = *x;
		game->y = *y;
	}
}

void	put_img(t_game *game, char c, int *x, int *y)
{
	if (c == '1' && !game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wall, *y * DIM1, *x * DIM2);
	else if (c == '0' && !game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->floor, (*y) * DIM1, (*x) * DIM2);
	else if (c == 'C' && !game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->collect, *y * DIM1, *x * DIM2);
	else if (c == 'E' && !game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->exit, *y * DIM1, *x * DIM2);
	else if (c == '1' && game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wall2, *y * DIM1, *x * DIM2);
	else if (c == '0' && game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->floor2, (*y) * DIM1, (*x) * DIM2);
	else if (c == 'C' && game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->collect2, *y * DIM1, *x * DIM2);
	else if (c == 'E' && game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->exit2, *y * DIM1, *x * DIM2);
}

void	init_enemy(t_game *game, int *x, int *y)
{
	if (!game->trip)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->enemy, *y * DIM1, *x * DIM2);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->enemy2, *y * DIM1, *x * DIM2);
}

void	ft_create(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{	
		y = 0;
		while (game->map[x][y] != '\n')
		{
			if (game->map[x][y] == 'P')
				put_player_img(game, &x, &y);
			else if (game->map[x][y] == 'D')
				init_enemy(game, &x, &y);
			else
				put_img(game, game->map[x][y], &x, &y);
			y++;
		}
		x++;
	}
}
