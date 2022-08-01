/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:17:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/08/01 13:02:26 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move(int key, t_game *game)
{
	if (key == UP)
		move_up(game);
	if (key == DOWN)
		move_down(game);
	if (key == LEFT)
		move_left(game);
	if (key == RIGHT)
		move_right(game);
	if (key == LEFT_ARROW)
		rotate_left(game);
	if (key == RIGHT_ARROW)
		rotate_right(game);
	return (0);
}

int	uwu(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		rotate_left(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = mlx_new_image(game->mlx, 640, 480);
		game->img.addr = mlx_get_data_addr(game->img.img,
				&game->img.bits, &game->img.line, &game->img.endian);
	}
	else if (key == 5)
	{
		rotate_right(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = mlx_new_image(game->mlx, 640, 480);
		game->img.addr = mlx_get_data_addr(game->img.img,
				&game->img.bits, &game->img.line, &game->img.endian);
	}
	else if (key == 1)
		mlx_mouse_hide();
	return (0);
}
