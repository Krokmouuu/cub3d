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

void drawline(t_game *game, int x, int draw_start, int draw_end, int color)
{
	while (draw_start < draw_end)
	{
		game->img.addr[draw_start * game->img.line / 4 + x] = color;
		//my_mlx_pixel_put(game->mlx, x, draw_start, GREEN);
		draw_start++;
	}
}

void	draw_floors(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		drawline(game, x, 0, HEIGHT / 2, SQR);
		drawline(game, x, HEIGHT / 2, HEIGHT, PURPLE);
		x++;
	}
}

void	init_struct(t_game *g, int x)
{
		g->ray.camera_x = 2 * x / (double)WIDTH - 1;
		g->ray.ray_dir_x = g->ray.dir_x + g->ray.plane_x * g->ray.camera_x;
		g->ray.ray_dir_y = g->ray.dir_y + g->ray.plane_y * g->ray.camera_x;
		g->ray.map_x = (int)g->ray.x;
		g->ray.map_y = (int)g->ray.y;
		g->ray.hit = 0;
		g->ray.side = 0;

		g->ray.delta_dist_x = define_delta(g->ray.ray_dir_x);
		g->ray.delta_dist_y = define_delta(g->ray.ray_dir_y);
		// if (g->ray.ray_dir_x < 0)
		// {
		// 	g->ray.step_x = -1;
		// 	g->ray.side_dist_x = (g->ray.x - g->ray.map_x) * g->ray.delta_dist_x;
		// }
		// else
		// {
		// 	g->ray.step_x = 1;
		// 	g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->ray.x) * g->ray.delta_dist_x;
		// }
		// if (g->ray.ray_dir_y < 0)
		// {
		// 	g->ray.step_y = -1;
		// 	g->ray.side_dist_y = (g->ray.y - g->ray.map_y) * g->ray.delta_dist_y;
		// }
		// else
		// {
		// 	g->ray.step_y = 1;
		// 	g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->ray.y) * g->ray.delta_dist_y;
		// }
		g->ray.step_x = define_step(g->ray.ray_dir_x);
		g->ray.step_y = define_step(g->ray.ray_dir_y);
		g->ray.side_dist_x = define_dist(g->ray.ray_dir_x,
			g->ray.x, g->ray.map_x, g->ray.delta_dist_x);
		g->ray.side_dist_y = define_dist(g->ray.ray_dir_y,
			g->ray.y, g->ray.map_y, g->ray.delta_dist_y);
}

void	draw_wall(t_game *g, int x, int color)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	if (g->ray.side == 0)
		perp_wall_dist = (g->ray.side_dist_x - g->ray.delta_dist_x);
	else
		perp_wall_dist = (g->ray.side_dist_y - g->ray.delta_dist_y);
	line_height = (int)(HEIGHT / perp_wall_dist);
	draw_start = (-line_height / 2) + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_height / 2) + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (x >= 318 && x <= 320)
		color = SQR;
	if ((int)g->ray.x < g->ray.map_x)
		color = PINK;
	if (g->ray.side == 1)
		color = color / 2;
	drawline(g, x, draw_start, draw_end, color);
}

void	print_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;

	while (y < game->y)
	{
		x = -1;
		while (game->map[y][++x])
		{
			print_map(game, y, x);
		}
		y++;
	}
}

void	raycast(t_game *g)
{
	int		x;
	int color = GREEN;
	x = -1;

	draw_floors(g);
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
			//printf("x == %d  | y == %d\n", g->ray.map_x, g->ray.map_y );
      		//if (g->ray.side == 1) 
			//	  color = GREEN;
			if (g->map[g->ray.map_y][g->ray.map_x] == '1')
				g->ray.hit = 1;
			//drawline(g, g->ray.x, g->ray.y, g->ray.map_x, g->ray.map_y);
		}
		draw_wall(g, x, color);
	}
	//print_minimap(g);
}
