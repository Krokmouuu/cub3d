/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:09:41 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/09 17:41:56 by bleroy           ###   ########.fr       */
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

void	check_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (++y < game->y - 1)
	{
		x = -1;
		while (game->map[y][++x] != '\n')
		{
			if (game->map[y][x] == '1' || game->map[y][x] == '0')
				continue ;
			else if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'S' || game->map[y][x] == 'W')
				continue ;
			else if (game->map[y][x] == ' ')
				continue ;
			else if (game->map[y][x] == '\n')
				continue ;
			else
				error("Unknow character\n");
		}
	}
}

void	fill_map(t_game *game)
{
	int		i;
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
	i = -1;
	while (++i < game->y)
		game->map[i] = get_next_line(fd);
	close (fd);
}

void	parsing_map(t_game *game)
{
	scale(game);
	game->map = ft_calloc(game->y, sizeof(char *));
	if (!game->map)
		error("Error\n");
	fill_map(game);
	check_map(game);
	check_wall(game);
	check_first_and_last(game);
	valid_map(game);
	get_player(game);
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
