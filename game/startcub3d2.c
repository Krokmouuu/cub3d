/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:00:20 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/21 18:16:55 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_color(t_game *game, int base_x, int base_y, int color)
{
	if (color == 0 && game->img.addr[base_y * 1024 + base_x] == 0)
		game->img.addr[base_y * 1024 + base_x] = PINK;
	else if (color == 1 && game->img.addr[base_y * 1024 + base_x] == 0)
		game->img.addr[base_y * 1024 + base_x] = PURPLE;
	else if (color == 2 && game->img.addr[base_y * 1024 + base_x] == 0)
		game->img.addr[base_y * 1024 + base_x] = GREEN;
	else if (color == 3 && game->img.addr[base_y * 1024 + base_x] == 0)
		game->img.addr[base_y * 1024 + base_x] = SQR;
}

void	draw_cube(t_game *game, int y, int x, int color)
{
	int	base_y;
	int	base_x;

	base_x = x;
	base_y = y * SQUARE_SIZE;
	if (x == 0)
		base_x = 0;
	if (y == 0)
		base_y = 1;
	while (base_y <= y * SQUARE_SIZE + SQUARE_SIZE)
	{
		while (base_x <= x * SQUARE_SIZE + SQUARE_SIZE)
		{
			if (base_y + 1 >= y * SQUARE_SIZE + SQUARE_SIZE
				|| base_x + 1 >= x * SQUARE_SIZE + SQUARE_SIZE)
				put_color(game, base_x, base_y, 3);
			put_color(game, base_x, base_y, color);
			base_x++;
		}
		base_x = x;
		base_y++;
	}
}

void	print_map(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		draw_cube(game, y, x, 0);
	else if (game->map[y][x] == '1')
		draw_cube(game, y, x, 1);
	else if (game->map[y][x] == 'N' || game->map[y][x] == 'E'
	|| game->map[y][x] == 'S' || game->map[y][x] == 'W')
	{
		game->ray.x = x;
		game->ray.y = y;
	}
	else
		return ;
}
