/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:06:12 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/30 18:24:46 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_struct(t_game *g, int x)
{
	g->ray.camera_x = 2 * x / (double)WIDTH - 1;
	g->ray.ray_dir_x = g->ray.dir_x + g->ray.plane_x * g->ray.camera_x;
	g->ray.ray_dir_y = g->ray.dir_y + g->ray.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->ray.x;
	g->ray.map_y = (int)g->ray.y;
	g->ray.hit = 0;
	g->ray.side = 0;
	g->ray.perp_wall_dist = 0;
	g->ray.side = 0;
	g->ray.line_height = 0;
	g->ray.color = GREEN;
	g->ray.delta_dist_x = define_delta(g->ray.ray_dir_x);
	g->ray.delta_dist_y = define_delta(g->ray.ray_dir_y);
	g->ray.step_x = define_step(g->ray.ray_dir_x);
	g->ray.step_y = define_step(g->ray.ray_dir_y);
	g->ray.side_dist_x = define_dist(g->ray.ray_dir_x,
			g->ray.x, g->ray.map_x, g->ray.delta_dist_x);
	g->ray.side_dist_y = define_dist(g->ray.ray_dir_y,
			g->ray.y, g->ray.map_y, g->ray.delta_dist_y);
	g->ray.tex_x = 0;
	g->ray.wall_x = 0;
	return (1);
}

int	rgb_to_hex(t_game *g)
{
	int	color;

	color = ((g->text.ceiling[0] << 16)
			+ (g->text.ceiling[1] << 8) + g->text.ceiling[2]);
	g->ray.ceiling = color;
	color = ((g->text.floor[0] << 16)
			+ (g->text.floor[1] << 8) + g->text.floor[2]);
	g->ray.floor = color;
	return (color);
}

double	define_delta(double r_dir)
{
	if (r_dir == 0)
		return (1e30);
	return (fabs(1 / r_dir));
}

double	define_dist(double r_dir, double r, double map, double d_dist)
{
	double	result;

	if (r_dir < 0)
	{
		result = ((r - map) * d_dist);
		return (result);
	}
	result = ((map + 1.0 - r) * d_dist);
	return (result);
}

double	define_step(double r_dir)
{
	if (r_dir < 0)
		return (-1.0);
	return (1.0);
}
