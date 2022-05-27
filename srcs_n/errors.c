/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:38:52 by jcourtoi          #+#    #+#             */
/*   Updated: 2022/05/27 11:40:39 by jcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_n/so_long.h"

int	ber_check(char *av)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (ft_strchr(av, '/'));
	if (tmp)
	{
		if (ft_strlen(tmp) == 5)
			return (0);
	}
	tmp = ft_strnstr(av, ".ber", ft_strlen(av));
	if (!tmp || ft_strlen(tmp) > 4)
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Error\n(ex : ./so_long {path_to_map.ber})\n");
		return (-2);
	}
	if (!ber_check(av[1]))
	{
		ft_printf("Error\nInvalid ext (.ber file expected)\n");
		return (-3);
	}	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThe file is missing or did not open correctly\n");
		return (fd);
	}
	if (fd < 0)
		close(fd);
	return (fd);
}

int	is_elem(char c)
{
	if (!(c == '1' || c == '0' || c == 'C'
			|| c == 'D' || c == 'E' || c == 'P'))
		return (ft_printf("Error\nInvalid element(s)\n"), 0);
	return (1);
}

int	short_map(t_game *game)
{
	int	c;
	int	p;
	int	y;

	c = 0;
	p = 0;
	if (game->height == 3)
	{
		y = 1;
		while (game->map[1][y])
		{
			if (game->map[1][y] == 'C')
				c++;
			if (game->map[1][y] == 'P')
				p++;
			if (game->map[1][y] == 'E' && c && !p)
			{
				ft_printf
					("Error\nCollectible not reachable\n");
				ft_close(game);
			}
			y++;
		}
	}
	return (0);
}
