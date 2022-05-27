/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:06:38 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:37:16 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	ft_get_moves(int keypress, t_game *game)
{
	if (keypress == ESC)
	{
		ft_printf("You escaped the game\n");
		ft_exit(game);
	}
	else if (keypress == A || keypress == LEFT)
		left_move(game);
	else if (keypress == D || keypress == RIGHT)
		right_move(game);
	else if (keypress == W || keypress == UP)
		move_up(game);
	else if (keypress == S || keypress == DOWN)
		move_down(game);
	return (0);
}

int	left_move(t_game *game)
{
	if (game->map[game->x][game->y - 1] != '1'
		|| (game->map[game->x][game->y - 1] != 'E' && game->collect))
	{
		if (game->map[game->x][game->y - 1] == 'C'
				||game->map[game->x][game->y - 1] == '0')
			ft_collect(game, game->map[game->x][game->y - 1], 'A');
		else if (game->map[game->x][game->y - 1] == 'E' && !(game->collect))
		{
			ft_printf("%d\n", ++game->steps);
			game->end = 1;
		}
		else if (game->map[game->x][game->y - 1] == 'D')
			ft_enemy(game);
		if (!game->end)
			ft_printf("%d\n", ++game->steps);
	}
	return (1);
}

int	right_move(t_game *game)
{
	if (game->map[game->x][game->y + 1] != '1'
		|| (game->map[game->x][game->y + 1] != 'E' && game->collect))
	{
		if (game->map[game->x][game->y + 1] == 'C'
				|| game->map[game->x][game->y + 1] == '0')
			ft_collect(game, game->map[game->x][game->y + 1], 'D');
		else if (game->map[game->x][game->y + 1] == 'E' && !(game->collect))
		{
			ft_printf("%d\n", ++game->steps);
			game->end = 1;
		}
		else if (game->map[game->x][game->y + 1] == 'D')
			ft_enemy(game);
		if (!game->end)
			ft_printf("%d\n", ++game->steps);
	}
	return (1);
}

int	move_up(t_game *game)
{
	if (game->map[game->x - 1][game->y] != '1'
		|| (game->map[game->x - 1][game->y] != 'E' && game->collect))
	{
		if (game->map[game->x - 1][game->y] == 'C'
				|| game->map[game->x - 1][game->y] == '0')
			ft_collect(game, game->map[game->x - 1][game->y], 'W');
		else if (game->map[game->x - 1][game->y] == 'E' && !(game->collect))
		{
			game->end = 1;
			ft_printf("%d\n", ++game->steps);
		}
		else if (game->map[game->x - 1][game->y] == 'D')
			ft_enemy(game);
		if (!game->end)
			ft_printf("%d\n", ++game->steps);
	}
	return (1);
}

int	move_down(t_game *game)
{
	if (game->map[game->x + 1][game->y] != '1'
		|| (game->map[game->x + 1][game->y] != 'E' && game->collect))
	{
		if (game->map[game->x + 1][game->y] == 'C'
				||game->map[game->x + 1][game->y] == '0')
			ft_collect(game, game->map[game->x + 1][game->y], 'S');
		else if (game->map[game->x + 1][game->y] == 'E' && !(game->collect))
		{
			ft_printf("%d\n", ++game->steps);
			game->end = 1;
		}
		else if (game->map[game->x + 1][game->y] == 'D')
			ft_enemy(game);
		if (!game->end)
			ft_printf("%d\n", ++game->steps);
	}
	return (1);
}
