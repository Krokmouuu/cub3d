/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:03:15 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/13 10:45:37 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	drawline(t_game *game, int x, int draw_start, int draw_end)
{
	while (draw_start < draw_end)
	{
		game->img.addr[draw_start * game->img.line / 4 + x] = game->ray.color;
		draw_start++;
	}
}

void	draw_floors(t_game *game)
{
	int	x;

	x = 0;
	rgb_to_hex(game);
	while (x < WIDTH)
	{
		game->ray.color = game->ray.ceiling;
		drawline(game, x, 0, HEIGHT / 2);
		game->ray.color = game->ray.floor;
		drawline(game, x, HEIGHT / 2, HEIGHT);
		x++;
	}
}

void	draw_wall(t_game *g, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;

	perp_wall_dist = (g->ray.side_dist_y - g->ray.delta_dist_y);
	if (g->ray.side == 0)
		perp_wall_dist = (g->ray.side_dist_x - g->ray.delta_dist_x);
	line_height = (int)(HEIGHT / perp_wall_dist);
	draw_start = ((line_height * -1) / 2) + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_height / 2) + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (g->ray.side == 0)
	{
		if (g->ray.step_x <= 0)	
			g->ray.color = 0x0099CCFF;
		if (g->ray.step_x > 0)
			g->ray.color = 0x0099FF66;
	}
	if (g->ray.side == 1)
	{
		if (g->ray.step_y <= 0)	
			g->ray.color = 0x00FFFF66;
		if (g->ray.step_y > 0)	
			g->ray.color = 0x009966FF;
	}
	drawline(g, x, draw_start, draw_end);
}

void	ray_values(t_game *g)
{
	if (g->ray.side_dist_x < g->ray.side_dist_y)
	{
		g->ray.side_dist_x += g->ray.delta_dist_x;
		g->ray.map_x += g->ray.step_x;
		g->ray.side = 0;
	}
	else
	{
		g->ray.side_dist_y += g->ray.delta_dist_y;
		g->ray.map_y += g->ray.step_y;
		g->ray.side = 1;
	}
}

void	raycast(t_game *g)
{
	int		x;

	x = -1;
	draw_floors(g);
	while (++x < WIDTH && init_struct(g, x))
	{
		while (g->ray.hit == 0)
		{
			ray_values(g);
			if (g->map[g->ray.map_y][g->ray.map_x] == '1')
				g->ray.hit = 1;
		}
		draw_wall(g, x);
	}
}
