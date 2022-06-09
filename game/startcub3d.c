/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/09 15:45:29 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keypressed(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		error("Game Closed !\n");
	}
	return (0);
}

int	closed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game Closed !\n");
	exit (0);
}

void	start(t_game *game)
{
	t_images	images;
	int			a;
	int			b;
	int			c;
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 720, 480, "tuc3D");
	images.img = mlx_new_image(game->mlx, 60, 60);
	images.addr = mlx_get_data_addr(images.img, &a, &b, &c);
	
	mlx_put_image_to_window(game->mlx, game->win, images.img, 60, 60);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}
