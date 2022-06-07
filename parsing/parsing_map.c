/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:09:41 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/07 17:37:09 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_x_y(int fd, t_game *game)
{
	size_t	i;
	char	*str;
	int		j;
	int		y;

	y = 0;
	i = 0;
	j = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (i < ft_strlen(str))
			i = ft_strlen(str);
		y++;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	game->y = y;
	game->x = i - 1;
}

void	parsing_map(t_game *game)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(game->file, 0x0000);
	i = getmap(fd);
	close (fd);
	fd = open(game->file, 0x0000);
	while (i > 1)
	{
		str = get_next_line(fd);
		free (str);
		i--;
	}
	j = 0;
	i = -1;
	while (++i < game->y)
		game->map[i] = get_next_line(fd);
	close (fd);
}

void	scale(t_game *game)
{
	int		map;
	int		fd;
	char	*str;

	fd = open(game->file, 0x0000);
	map = getmap(fd);
	close (fd);
	fd = open(game->file, 0x0000);
	while (map > 1)
	{
		str = get_next_line(fd);
		free (str);
		map--;
	}
	get_x_y(fd, game);
}
