/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:54:19 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/18 17:54:03 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_door(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->y - 1)
	{
		x = -1;
		while (game->map[y][++x] != '\n')
		{
			if (game->map[y][x] == 'D'
				&& (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'))
				break ;
			if (game->map[y][x] == 'D'
				&& (game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1'))
				break ;
			else if (game->map[y][x] != 'D')
				continue ;
			else
				error("Invalid Map\n");
		}
	}
}
