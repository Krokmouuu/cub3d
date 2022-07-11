/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/11 09:09:56 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_check_map(t_game *game)
{
	// if (game->player.direction == 'E')
	// {
	// 	game->ray.dir_x = 1;
	// 	game->ray.dir_y = 0;
	// }
	// if (game->player.direction == 'N')
	// {
	// 	game->ray.dir_x = -1;
	// 	game->ray.dir_y = 0;
	// }
	game->img.img = mlx_new_image(game->mlx, 640, 480);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits, &game->img.line, &game->img.endian);
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
