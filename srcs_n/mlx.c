/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:47:04 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:37:01 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	ft_display(t_game *game)
{
	ft_create(game);
	if ((game->collect == 0 || (game->enemy && !game->life)) && game->end == 1)
	{
		if (game->enemy && game->life && game->end && !game->collect)
		{
			ft_printf("YOU WON in %d steps and %d / %d lives left\n",
				game->steps, game->life, game->enemy);
			if (!game->trip)
				ft_printf("BUT this is the sad world\n");
			else
				ft_printf("AND this is the happy world *_*\n");
		}
		else if (!game->enemy && !game->collect && game->end)
			ft_printf("YOU WON in %d steps\n", game->steps);
		ft_exit(game);
	}
	return (1);
}

int	ft_mlx(t_game *game)
{
	mlx_hook(game->win, ON_DESTROY, 1L << 0, ft_exit, game);
	mlx_hook(game->win, 2, 1L << 0, ft_get_moves, game);
	mlx_loop_hook(game->mlx, ft_display, game);
	mlx_loop(game->mlx);
	return (1);
}
