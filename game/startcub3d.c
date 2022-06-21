/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/20 13:52:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_color(t_game *game, int base_x, int base_y, int color)
{
	if (color == 0 && game->images.addr[base_y * 1024 + base_x] == 0)
		game->images.addr[base_y * 1024 + base_x] = GREEN;
	else if (color == 1 && game->images.addr[base_y * 1024 + base_x] == 0)
		game->images.addr[base_y * 1024 + base_x] = RED;
	else if (color == 2 && game->images.addr[base_y * 1024 + base_x] == 0)
		game->images.addr[base_y * 1024 + base_x] = WHITE;
	else if (color == 3 && game->images.addr[base_y * 1024 + base_x] == 0)
		game->images.addr[base_y * 1024 + base_x] = 0x00003399;
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
	while (base_y <= y * 20 + 10)
	{
		while (base_x <= x * 20 + 10)
		{
			if (base_y + 1 >= y * 20 + 10 || base_x + 1 >= x * 20 + 10)
				put_color(game, base_x, base_y, 3);
			else
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
	{
		game->player.x = x * 20;
		game->player.y = y * 20;
	}
	else
		return ;
}

void	start_check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->images.img = mlx_new_image(game->mlx, 1024, 512);
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
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	game->player.delta_x = cos(game->player.angle) * 5;
	game->player.delta_y = sin(game->player.angle) * 5;
	draw_player(game, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->images.img, 0, 0);
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1024, 512, "tuc3D");
	start_check_map(game);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}
