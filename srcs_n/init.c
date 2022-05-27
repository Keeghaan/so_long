/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:16:22 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 15:08:14 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

static int	nb_elem(t_game *game)
{
	int	err;

	err = 0;
	if (game->exit != 1)
	{
		err++;
		ft_printf
			("Error\n%d exit(s) (expected : 1)\n", game->exit);
	}
	if (game->player != 1)
	{
		err++;
		ft_printf
			("Error\n%d player(s) (expected : 1)\n", game->player);
	}
	if (game->collect < 1)
	{
		err++;
		ft_printf
			("Error\nThere is no collectibles (expected : At least 1)\n");
	}
	if (err)
		return (0);
	return (1);
}

static char	**initialize(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->height)
	{
		game->map[x] = NULL;
		x++;
	}
	game->map[x] = NULL;
	return (game->map);
}

int	get_map(t_game *game, int fd)
{
	int		i;

	i = 0;
	game->map = malloc(game->width * (game->height + 1));
	if (!game->map)
		return (ft_printf("Error\nMalloc failed\n"), 0);
	initialize(game);
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		if (!ft_parsing(game->map[i], i, game->height, game->width))
		{
			get_next_line(-1);
			close(fd);
			ft_close(game);
		}
		else
			check_elem(game, game->map[i], i);
		i++;
	}
	game->map[i] = NULL;
	get_next_line(-1);
	close(fd);
	return (1);
}

void	ft_init(char *av, t_game *game, int fd)
{
	if (!get_height(fd, game))
		ft_close(game);
	if (game->height == game->width)
	{
		ft_printf("Error\nNot rectangle\n");
		ft_close(game);
	}
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf
			("Error\nThe file isnt correct or did not reoppen\n");
		close(fd);
		ft_close(game);
	}
	get_map(game, fd);
	if (!game->map || !nb_elem(game))
		ft_close(game);
	short_map(game);
}
