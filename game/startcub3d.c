/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/21 18:34:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
