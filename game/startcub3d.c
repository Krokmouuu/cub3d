/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/09 18:33:38 by bleroy           ###   ########.fr       */
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
		// move(key, game);
	return (0);
}

int	closed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game Closed !\n");
	exit (0);
}

void	my_mlx_pixel_put(t_images *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}

void	start(t_game *game)
{
	t_images	images;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Hello world!");
	images.img = mlx_new_image(game->mlx, 1920, 1080);
	images.addr = mlx_get_data_addr(images.img, &images.bits, &images.line,
		&images.endian);
	my_mlx_pixel_put(&images, 5, 890, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, images.img, 0, 0);
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}
