/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:03:15 by ple-berr          #+#    #+#             */
/*   Updated: 2022/06/28 16:03:16 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_game *g, int x)
{
		g->ray.camera_x = 2 * x / (double)WIDTH - 1;
		g->ray.ray_dir_x = g->ray.delta_x + g->ray.plane_x * g->ray.camera_x;
		g->ray.ray_dir_y = g->ray.delta_y + g->ray.plane_y * g->ray.camera_x;
		g->ray.map_x = (int)g->ray.x;
		g->ray.map_y = (int)g->ray.y;
		g->ray.hit = 0;
		g->ray.side = 0;
		g->ray.delta_dist_x = define_delta(g->ray.ray_dir_x);
		g->ray.delta_dist_y = define_delta(g->ray.ray_dir_y);
		g->ray.step_x = define_step(g->ray.ray_dir_x);
		g->ray.step_y = define_step(g->ray.ray_dir_y);
		g->ray.side_dist_x = define_dist(g->ray.ray_dir_x,
			g->ray.x, g->ray.map_x, g->ray.delta_dist_x);
		g->ray.side_dist_y = define_dist(g->ray.ray_dir_y,
			g->ray.y, g->ray.map_y, g->ray.delta_dist_y);
}

void	raycast(t_game *g)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		init_struct(g, x);
		while (g->ray.hit == 0)
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
			if (g->map[g->ray.map_y / 20][g->ray.map_x / 20] == '1')
				g->ray.hit = 1;
			drawline(g, g->ray.x, g->ray.y, g->ray.map_x, g->ray.map_y);
		}
	}
}

void	clearcast(t_game *g)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		init_struct(g, x);
		while (g->ray.hit == 0)
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
			if (g->map[g->ray.map_y / 20][g->ray.map_x / 20] == '1')
				g->ray.hit = 1;
			clearline(g, g->ray.x, g->ray.y, g->ray.map_x, g->ray.map_y);
		}
	}
}
