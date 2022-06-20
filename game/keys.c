/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:39:38 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 11:39:54 by bleroy           ###   ########.fr       */
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
		mlx_clear_window(game->mlx, game->win);
		move(key, game);
		mlx_put_image_to_window(game->mlx, game->win, game->images.img, 0, 0);
	}
	return (0);
}

int	closed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game Closed !\n");
	exit (0);
}
