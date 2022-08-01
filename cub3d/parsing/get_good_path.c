/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_good_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:39:47 by bleroy            #+#    #+#             */
/*   Updated: 2022/08/01 17:00:08 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ouinorth(t_game *g, char *str)
{
	size_t	i;
	size_t	j;

	if (str != NULL)
		free (str);
	i = 0;
	j = ft_strlen(g->text.north);
	str = malloc(j + 1 * sizeof(char));
	str[0] = '.';
	while (g->text.north[i++] != '\0')
	{
		if (g->text.north[i + 1] == '\n')
		{
			str[i] = g->text.north[i];
			i++;
			break ;
		}
		str[i] = g->text.north[i];
	}
	str[i] = '\0';
	return (str);
}

char	*ouisouth(t_game *g, char *str)
{
	size_t	i;
	size_t	j;

	if (str != NULL)
		free (str);
	i = 0;
	j = 0;
	j = ft_strlen(g->text.south);
	str = malloc(j + 1 * sizeof(char));
	str[0] = '.';
	while (g->text.south[i++] != '\0')
	{
		if (g->text.south[i + 1] == '\n')
		{
			str[i] = g->text.south[i];
			i++;
			break ;
		}
		str[i] = g->text.south[i];
	}
	str[i] = '\0';
	return (str);
}

char	*ouieast(t_game *g, char *str)
{
	size_t	i;
	size_t	j;

	if (str != NULL)
		free (str);
	i = 0;
	j = 0;
	j = ft_strlen(g->text.east);
	str = malloc(j + 1 * sizeof(char));
	str[0] = '.';
	while (g->text.east[i++] != '\0')
	{
		if (g->text.east[i + 1] == '\n')
		{
			str[i] = g->text.east[i];
			i++;
			break ;
		}
		str[i] = g->text.east[i];
	}
	str[i] = '\0';
	return (str);
}

char	*ouiwest(t_game *g, char *str)
{
	size_t	i;
	size_t	j;

	if (str != NULL)
		free (str);
	i = 0;
	j = 0;
	j = ft_strlen(g->text.west);
	str = malloc(j + 1 * sizeof(char));
	str[0] = '.';
	while (g->text.west[i++] != '\0')
	{
		if (g->text.west[i + 1] == '\n')
		{
			str[i] = g->text.west[i];
			i++;
			break ;
		}
		str[i] = g->text.west[i];
	}
	str[i] = '\0';
	return (str);
}
