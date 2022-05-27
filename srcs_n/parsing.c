/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:20:32 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 15:08:59 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	get_height(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || *line == '\n' || *line == ' ')
	{
		get_next_line(-1);
		close(fd);
		ft_printf("Error\nSomething's wrong whith the map\n");
		free(line);
		ft_close(game);
	}
	game->width = ft_strlen(line) - 1;
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (1);
}

int	ft_parsing(char *tab, int i, int height, int width)
{
	int	j;

	j = 0;
	if (!tab || *tab == '\n' || *tab == ' ' || (i == height && *tab != '1'))
		return (ft_printf("Error\nSomething is not correct in the map\n"), 0);
	if (ft_strlen(tab) != width + 1)
		return (ft_printf("Error\nSomething's wrong with the dimensions\n"), 0);
	while (tab[j] != '\n')
	{
		if (!is_elem(tab[j]))
			return (0);
		if ((i == 0 || i == height - 1) && (tab[j] != '1'))
			return (ft_printf("Error\nInvalid wall\n"), 0);
		if (tab[0] == '1' && tab[ft_strlen(tab) - 2] != '1')
			return (ft_printf("Error\nInvalid wall\n"), 0);
		j++;
	}
	return (1);
}

void	check_elem(t_game *game, char *map, int i)
{
	int	j;

	j = 0;
	while (map[j] != '\n')
	{
		if (map[j] == 'E')
			game->exit++;
		if (map[j] == 'C')
			game->collect++;
		if (map[j] == 'D')
		{
			game->enemy++;
			game->life++;
		}
		if (map[j] == 'P')
		{
			game->player++;
			game->x = i;
			game->y = j;
		}
		j++;
	}
}
