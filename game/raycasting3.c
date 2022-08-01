/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:50:35 by ple-berr          #+#    #+#             */
/*   Updated: 2022/08/01 12:20:31 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawline(t_game *game, int x, int draw_start, int draw_end)
{
	while (draw_start < draw_end)
	{
		game->img.addr[draw_start * game->img.line + x] = game->ray.color;
		draw_start++;
	}
}

void	draw_floors(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	rgb_to_hex(game);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
			put_pixel(&game->img, x, y++, game->ray.ceiling);
		while (y < HEIGHT)
			put_pixel(&game->img, x, y++, game->ray.floor);
		x++;
	}
}

unsigned int	get_data_color(int x, int y, void *addr, t_images *img)
{
	char	*dst;

	dst = addr + (y * img->line + x * (img->bits / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_images *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (!color)
		return ;
	dst = img->addr + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}
