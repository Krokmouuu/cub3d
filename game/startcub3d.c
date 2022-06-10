/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 18:15:52 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//* je voulais print des carrés pour chaque 1 et 0 mais ca marche pas

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->images.addr + (y * game->images.line + x * (game->images.bits / 8));
	*(unsigned int*)dst = color;
}

void	print_map(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
	{
		my_mlx_pixel_put(game, x, y, 0x0000FF00);
	}
	else if (game->map[y][x] == '0')
	{
		my_mlx_pixel_put(game, x, y, 0x00FF0000);
	}
	else
		return ;
}

void	start_check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->images.img = mlx_new_image(game->mlx, 800, 600);
	game->images.addr = mlx_get_data_addr(game->images.img,
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
	mlx_put_image_to_window(game->mlx, game->win, game->images.img, 0, 0);
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 600, "tuc3D");
	start_check_map(game);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}