/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/13 17:10:48 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_color(t_game *game, int base_x, int base_y, int color)
{
	if (color == 0 && game->images.addr[base_y * 1920 + base_x] == 0)
		game->images.addr[base_y * 1920 + base_x] = GREEN;
	else if (color == 1 && game->images.addr[base_y * 1920 + base_x] == 0)
		game->images.addr[base_y * 1920 + base_x] = RED;
	else if (color == 2 && game->images.addr[base_y * 1920 + base_x] == 0)
		game->images.addr[base_y * 1920 + base_x] = WHITE;
}

void	draw_cube(t_game *game, int y, int x, int color)
{
	int	base_y;
	int	base_x;

	base_x = x;
	base_y = y * 10;
	if (x == 0)
		base_x = 0;
	if (y == 0)
		base_y = 1;
	while (base_y <= y * 10 + 10)
	{
		while (base_x <= x * 10 + 10)
		{
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
	else if (game->map[y][x] == 'N')
		draw_cube(game, y, x, 2);
	else
		return ;
}

void	start_check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->images.img = mlx_new_image(game->mlx, 1920, 1080);
	game->images.addr = (int *)mlx_get_data_addr(game->images.img,
			&game->images.bits, &game->images.line, &game->images.endian);
	while (y < game->y)
	{
		x = -1;
		while (game->map[y][++x])
		{
			print_map(game, y, x);
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->images.img, 100, 100);
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "tuc3D");
	start_check_map(game);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}
