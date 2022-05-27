/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:11:13 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 14:31:55 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		game->map[i] = NULL;
		free(game->map);
		game->map = NULL;
	}
	free(game->img);
	game->img = NULL;
	free(game->mlx);
	game->mlx = NULL;
	free(game);
	game = NULL;
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	*game;

	fd = 0;
	fd = check_args(ac, av);
	if (fd < 0)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), 1);
	if (!ft_init_game(game, av[1]))
		ft_close(game);
	ft_init(game->av, game, fd);
	game->win = mlx_new_window(game->mlx, game->width * DIM1,
			game->height * DIM2, "so_long");
	if (!game->win)
		ft_close(game);
	ft_mlx(game);
	ft_exit(game);
	return (0);
}
