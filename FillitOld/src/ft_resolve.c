/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:59:36 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/18 19:54:52 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void		ft_deletemap(char **tetris, char letter)
{
	int		i;
	int		j;

	j = 0;
	while (tetris[j])
	{
		i = 0;
		while (tetris[j][i])
		{
			if (tetris[j][i] == letter)
				tetris[j][i] = '.';
			i++;
		}
		j++;
	}
}

static char		ft_checkletter(char *map)
{
	char	letter;
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_isalpha(map[i]))
			letter = map[i];
		i++;
	}
	return (letter);
}

static int		ft_mapisvalid(char **tetris, char *map, int x, int y)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = x;
	while (map[++i])
	{
		if (ft_isalpha(tetris[y][x]) && ft_isalpha(map[i]))
			return (0);
		if (map[i] != '\n')
			x++;
		if (x > g_cube)
			return (0);
		if (map[i] == '\n')
		{
			y++;
			x = tmp;
			if (y > g_cube - 1)
				return (0);
		}
	}
	return (1);
}

static int		ft_putintetris(char **tetris, char *map, int x, int y)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = x;
	if (ft_mapisvalid(tetris, map, x, y))
		while (map[++i])
		{
			if (map[i] == '.')
				x++;
			if (ft_isalpha(map[i]))
			{
				if (tetris[y][x] == '.')
					tetris[y][x++] = map[i];
			}
			if (map[i] == '\n')
			{
				y++;
				x = tmp;
			}
		}
	else
		return (0);
	return (1);
}

char			**ft_fillit(char **tetris, char **map, int x, int y)
{
	while (!(ft_putintetris(tetris, *map, x, y)))
	{
		x++;
		if (x > g_cube)
		{
			y++;
			x = 0;
			if (y > g_cube - 1)
				return (NULL);
		}
	}
	if (map + 1 && *(map + 1))
	{
		while (!(ft_fillit(tetris, map + 1, 0, 0)))
		{
			ft_deletemap(tetris, ft_checkletter(*map));
			return (ft_fillit(tetris, map, ++x, y));
		}
	}
	return (tetris);
}
