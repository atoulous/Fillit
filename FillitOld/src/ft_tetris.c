/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:32:10 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/18 19:57:29 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		*ft_push_top(char *map, char letter, int i, int y)
{
	while (map[i] != letter)
		i++;
	if (i < 4)
	{
		while (y != 4)
			if (map[i++] == letter)
				y++;
		while (i < 19)
		{
			if (map[i] == '\n')
				i++;
			map[i++] = '.';
		}
	}
	else
	{
		i = i - (i - 5);
		while (i < 20)
			map[y++] = map[i++];
		return (ft_push_top(map, letter, 0, 0));
	}
	return (map);
}

static int	ft_sqrt(int nb)
{
	int		racine;

	racine = 0;
	while (racine * racine < nb)
		racine++;
	if (racine * racine >= nb)
		return (racine);
	return (0);
}

void		ft_free(char **map, char *tmp, char **tetris)
{
	int		i;

	i = 0;
	free(tmp);
	while (map[i])
		free(map[i++]);
	free(map);
	i = 0;
	while (tetris[i])
		free(tetris[i++]);
	free(tetris);
}

void		ft_tetris(char *tmp)
{
	char	**map;
	char	**tetris;
	int		i;

	g_cube = ((ft_strlen(tmp) + 1) / 21);
	if ((map = init_map(tmp, -1, g_cube)))
	{
		g_cube = ft_sqrt(g_cube * 4);
		tetris = ft_create_tet(g_cube);
		while ((tetris = ft_fillit(tetris, map, 0, 0)) == NULL)
		{
			g_cube++;
			free(tetris);
			tetris = ft_create_tet(g_cube);
		}
		i = -1;
		while (tetris[++i])
			ft_putstr(tetris[i]);
		ft_free(map, tmp, tetris);
	}
	else
		ft_putstr("error\n");
}
