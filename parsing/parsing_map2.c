/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:38:53 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/08 14:31:52 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				(game->map[y - 1][x] == ' ' || game->map[y - 1][x] == '\0'))
				error("Invalid map\n");
			if (game->map[y][x] == '0' &&
				(game->map[y + 1][x] == ' ' || game->map[y + 1][x] == '\0'))
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
