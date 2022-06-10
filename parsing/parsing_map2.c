/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:38:53 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 18:21:15 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player2(t_game *game, int y, int x, char c)
{
	if (game->map[y - 1][x] != '0' && game->map[y - 1][x] != '1')
		error("Invalid map\n");
	if (game->map[y + 1][x] != '0' && game->map[y + 1][x] != '1')
		error("Invalid map\n");
	if (game->map[y][x - 1] != '0' && game->map[y][x - 1] != '1')
		error("Invalid map\n");
	if (game->map[y][x + 1] != '0' && game->map[y][x + 1] != '1')
		error("Invalid map\n");
	if (c == 'N')
		game->player.direction = 'N';
	if (c == 'E')
		game->player.direction = 'E';
	if (c == 'S')
		game->player.direction = 'S';
	if (c == 'W')
		game->player.direction = 'W';
}

void	get_player(t_game *game)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	while (++y < game->y - 1)
	{
		x = -1;
		while (game->map[y][++x] != '\n')
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'S' || game->map[y][x] == 'W')
			{
				get_player2(game, y, x, game->map[y][x]);
				game->player.x = x;
				game->player.y = y;
				player++;
			}
		}
	}
	if (player < 1)
		error("Missing Player\n");
	else if (player > 1)
		error("Too many players\n");
}

void	valid_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (++y < game->y - 1)
	{
		x = 0;
		while (game->map[y][x] != '\n')
		{
			if ((game->map[y][x] == '0') &&
				(game->map[y - 1][x] == ' ' || game->map[y - 1][x] == '\n'))
				error("Invalid map\n");
			if (game->map[y][x] == '0' &&
				(game->map[y + 1][x] == ' ' || game->map[y + 1][x] == '\0'
					|| game->map[y + 1][x] == '\n'))
				error("Invalid map\n");
			if (game->map[y][x] == '0' &&
				(game->map[y][x - 1] == ' ' || game->map[y][x - 1] == '\n'))
				error("Invalid map\n");
			if (game->map[y][x] == '0' &&
				(game->map[y][x - 1] == ' ' || game->map[y][x + 1] == '\n'))
				error("Invalid map\n");
			x++;
		}
	}
}

void	check_first_and_last(t_game *game)
{	
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] == '\n')
			break ;
		if (game->map[0][x] != '1' && game->map[0][x] != ' ')
			error("Invalid map\n");
		x++;
	}
	x = 0;
	while (game->map[game->y - 1][x])
	{
		if (game->map[game->y - 1][x] != '1'
			&& game->map[game->y - 1][x] != ' ')
			error("Invalid map\n");
		x++;
	}
}

void	check_wall(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = -1;
	while (++y < game->y)
	{
		if (game->map[y][0] == '\n')
			error("Invalid map\n");
		else
		{
			i = 0;
			while (game->map[y][i] == ' ' || game->map[y][i] == '\t')
				i++;
			if (game->map[y][i] != '1')
				error("Invalid Map\n");
			if (game->map[y][i] == '1' && game->map[y][i + 1] == '\n')
				error("Invalid Map\n");
		}
	}
}
