/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:42:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/07 11:32:44 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	c = malloc(size * count);
	if (c == NULL)
		return (NULL);
	while (i < size * count)
		c[i++] = '\0';
	return ((void *)c);
}
