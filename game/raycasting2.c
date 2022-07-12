/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:06:12 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/11 17:07:33 by ple-berr         ###   ########.fr       */
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
	g->ray.color = GREEN;
	g->ray.delta_dist_x = define_delta(g->ray.ray_dir_x);
	g->ray.delta_dist_y = define_delta(g->ray.ray_dir_y);
	g->ray.step_x = define_step(g->ray.ray_dir_x);
	g->ray.step_y = define_step(g->ray.ray_dir_y);
	g->ray.side_dist_x = define_dist(g->ray.ray_dir_x,
			g->ray.x, g->ray.map_x, g->ray.delta_dist_x);
	g->ray.side_dist_y = define_dist(g->ray.ray_dir_y,
			g->ray.y, g->ray.map_y, g->ray.delta_dist_y);
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

double	define_delta(double rayDir)
{
	if (rayDir == 0)
		return (1.7976931348623157E+308);
	return (fabs(1 / rayDir));
}

double	define_dist(double rayDir, double ray, double map, double deltaDist)
{
	double	result;

	if (rayDir < 0)
	{
		result = ((ray - map) * deltaDist);
		return (result);
	}
	result = ((map + 1.0 - ray) * deltaDist);
	return (result);
}

double	define_step(double rayDir)
{
	if (rayDir < 0)
		return (-1.0);
	return (1);
}
