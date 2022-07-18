/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_function_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:01:24 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/18 10:15:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_game *g)
{
	double	old_dir_x;
	double	r;
	double	old_plane_x;

	r = -0.15;
	old_dir_x = g->ray.dir_x;
	g->ray.dir_x = g->ray.dir_x * cos(r) - g->ray.dir_y * sin(r);
	g->ray.dir_y = old_dir_x * sin(r) + g->ray.dir_y * cos(r);
	old_plane_x = g->ray.plane_x;
	g->ray.plane_x = g->ray.plane_x * cos(r) - g->ray.plane_y * sin(r);
	g->ray.plane_y = old_plane_x * sin(r) + g->ray.plane_y * cos(r);
	raycast(g);
}

void	rotate_right(t_game *g)
{
	double	old_dir_x;
	double	r;
	double	old_plane_x;

	r = 0.15;
	old_dir_x = g->ray.dir_x;
	g->ray.dir_x = (g->ray.dir_x * cos(r)) - g->ray.dir_y * sin(r);
	g->ray.dir_y = old_dir_x * sin(r) + g->ray.dir_y * cos(r);
	old_plane_x = g->ray.plane_x;
	g->ray.plane_x = (g->ray.plane_x * cos(r)) - g->ray.plane_y * sin(r);
	g->ray.plane_y = old_plane_x * sin(r) + g->ray.plane_y * cos(r);
	raycast(g);
}
