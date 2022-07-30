/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:03:15 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/30 11:17:04 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	other_drawline(t_game *g, int x, int draw_start, int draw_end)
{
	unsigned int	color;
	double			step;
	double			texpos;

	step = (double)(1.0 * TEX_H / (double)g->ray.line_height);
	texpos = (draw_start - (HEIGHT / 2) + (g->ray.line_height / 2)) * step;
	g->ray.line_height = height(g);
	draw_texture(g);
	while (draw_start < draw_end)
	{
		g->ray.tex_y = (int)texpos & (TEX_H - 1);
		texpos += step;
		color = choose_texture(g, g->ray.side);
		put_pixel(&g->img, x, draw_start, color);
		draw_start++;
	}
}

void	draw_texture(t_game *g)
{
	g->ray.wall_x = (g->ray.x + g->ray.perp_wall_dist) * g->ray.ray_dir_x;
	if (g->ray.side == 0)
		g->ray.wall_x = (g->ray.y + g->ray.perp_wall_dist) * g->ray.ray_dir_y;
	g->ray.wall_x -= floor(g->ray.wall_x);
	g->ray.tex_x = (int)(g->ray.wall_x * TEX_H);
	if ((g->ray.side == 0 && g->ray.ray_dir_x > 0)
		|| (g->ray.side == 1 && g->ray.ray_dir_y < 0))
		g->ray.tex_x = TEX_H - g->ray.tex_x - 1;
}

void	draw_wall(t_game *g, int x)
{
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;

	perp_wall_dist = (g->ray.side_dist_y - g->ray.delta_dist_y);
	if (g->ray.side == 0)
		perp_wall_dist = (g->ray.side_dist_x - g->ray.delta_dist_x);
	g->ray.line_height = (int)(HEIGHT / perp_wall_dist);
	draw_start = (g->ray.line_height * -1) / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (g->ray.line_height / 2) + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	choose_texture(g, g->ray.side);
	other_drawline(g, x, draw_start, draw_end);
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
	clear_screen(g);
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
