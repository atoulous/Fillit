/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:38:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/19 14:31:28 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

int		g_cube;

void	ft_putstr(char const *str);
size_t	ft_strlen(char const *str);
void	ft_tetris(char *file);
char	**init_map(char *s, int j, int cube);
char	*ft_strnew(int len);
char	**ft_create_tet(int cube);
char	*ft_push_top(char *map, char letter, int i, int y);
void	ft_putnbr(char c);
void	ft_putchar(char c);
char	**ft_fillit(char **tetris, char **map, int x, int y);
int		ft_isalpha(char c);

#endif
