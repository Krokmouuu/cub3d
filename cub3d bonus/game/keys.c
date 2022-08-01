/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:39:38 by bleroy            #+#    #+#             */
/*   Updated: 2022/08/01 13:01:49 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keypressed(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		error("Game Closed !\n");
	}
	else if (key == UP || key == LEFT || key == RIGHT || key == DOWN
		|| key == LEFT_ARROW || key == RIGHT_ARROW)
	{
		move(key, game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = mlx_new_image(game->mlx, 640, 480);
		game->img.addr = mlx_get_data_addr(game->img.img,
				&game->img.bits, &game->img.line, &game->img.endian);
	}
	else if (key == 257)
		mlx_mouse_show();
	return (0);
}

int	closed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game Closed !\n");
	exit (0);
}
