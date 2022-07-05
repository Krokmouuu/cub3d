/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/21 18:40:25 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_check_map(t_game *game)
{
	// int	x;
	int	y;

	y = 0;
	game->ray.dir_x = 1;
	game->ray.dir_y = 1;
	game->img.img = mlx_new_image(game->mlx, 640, 480);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits, &game->img.line, &game->img.endian);
	// while (y < game->y)
	// {
	// 	x = -1;
	// 	while (game->map[y][++x])
	// 	{
	// 		print_map(game, y, x);
	// 	}
	// 	y++;
	// }
	// game->player.direction -= 0.1;
	// if (game->player.direction < 0)
	// 	game->player.direction += 2 * PI;
	// game->ray.delta_x = cos(game->player.direction) * 5;
	// game->ray.delta_y = sin(game->player.direction) * 5;
	// draw_player(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	start(t_game *game)
{
	start_check_map(game);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}
