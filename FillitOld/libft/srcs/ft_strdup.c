/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:35:55 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:35:56 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * ft_strlen(s) + 1)))
		return (tmp);
	if (!s)
		return (tmp);
	tmp = (char *)malloc(sizeof(*tmp) * ft_strlen(s) + 1);
	return (tmp = ft_strcpy(tmp, s));
}
