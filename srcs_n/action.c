/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:58:24 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 16:03:49 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

void	ft_counter(t_game *game)
{
	char	*counter;
	int		trgb;

	counter = ft_itoa(game->steps);
	trgb = create_trgb(T, R, G, B);
	mlx_string_put(game->mlx, game->win, DIM1, DIM2
		+ 100, get_b(trgb), counter);
	free(counter);
}

static void	ft_player_moves(t_game *game, int key)
{
	if (key == 'W')
	{
		game->map[game->x - 1][game->y] = 'P';
		game->x--;
	}
	else if (key == 'A')
	{
		game->map[game->x][game->y - 1] = 'P';
		game->y--;
	}
	else if (key == 'S')
	{
		game->map[game->x + 1][game->y] = 'P';
		game->x++;
	}
	else if (key == 'D')
	{
		game->map[game->x][game->y + 1] = 'P';
		game->y++;
	}
}

void	ft_collect(t_game *game, char c, char key)
{
	game->map[game->x][game->y] = '0';
	if (c == 'C')
	{
		game->trip = 1;
		game->collect--;
	}
	ft_player_moves(game, key);
}

void	ft_enemy(t_game *game)
{
	game->life--;
	ft_printf("%d / %d lives left\n", game->life, game->enemy);
	if (game->enemy > 1)
		game->trip = 0;
	if (!game->life)
	{
		if (game->collect)
			ft_printf
				("You lost and left %d riceball(s)\n", game->collect);
		if (!game->collect)
			ft_printf
				("You've ate all the riceballs but got caught by Meowth\n");
		game->end = 1;
		ft_printf("GAME OVER\n");
	}
}
