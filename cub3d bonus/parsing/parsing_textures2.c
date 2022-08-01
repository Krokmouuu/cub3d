/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:41:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/18 12:50:21 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	getouttab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free (tab);
}

int	checktab(char c)
{
	if (c == '\n' || c == '\0')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	checkstr(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			error("Invalid RGB\n");
		if (str[i] == ',')
			j++;
	}
	if (j != 2)
		return (1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == ',' && (str[i + 1] == '\n' || str[i + 1] == ' '))
			return (1);
	return (0);
}
