/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:27:03 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:35:58 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->floor);
	mlx_destroy_image(game->mlx, game->img->collect);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->enemy);
	mlx_destroy_image(game->mlx, game->img->wall2);
	mlx_destroy_image(game->mlx, game->img->floor2);
	mlx_destroy_image(game->mlx, game->img->collect2);
	mlx_destroy_image(game->mlx, game->img->player2);
	mlx_destroy_image(game->mlx, game->img->exit2);
	mlx_destroy_image(game->mlx, game->img->enemy2);
	mlx_destroy_display(game->mlx);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->floor);
	mlx_destroy_image(game->mlx, game->img->collect);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->enemy);
	mlx_destroy_image(game->mlx, game->img->wall2);
	mlx_destroy_image(game->mlx, game->img->floor2);
	mlx_destroy_image(game->mlx, game->img->collect2);
	mlx_destroy_image(game->mlx, game->img->player2);
	mlx_destroy_image(game->mlx, game->img->exit2);
	mlx_destroy_image(game->mlx, game->img->enemy2);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_game(game);
	exit(EXIT_SUCCESS);
}
