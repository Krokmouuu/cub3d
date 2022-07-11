/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:05:51 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/11 16:55:35 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x + g->ray.dir_x * 0.1)] != '1')
		g->ray.x += g->ray.dir_x * 0.1;
	if (g->map[(int)(g->ray.y + g->ray.dir_y * 0.1)][(int)g->ray.x] != '1')
		g->ray.y += g->ray.dir_y * 0.1;
	raycast(g);
}

void	move_down(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x - g->ray.dir_x)] != '1')
		g->ray.x -= g->ray.dir_x * 0.1;
	if (g->map[(int)(g->ray.y - g->ray.dir_y)][(int)g->ray.x] != '1')
		g->ray.y -= g->ray.dir_y * 0.1;
	raycast(g);
}

void	move_left(t_game *g)
{	
	if (g->map[(int)g->ray.y][(int)(g->ray.x + g->ray.dir_y * 0.11)] != '1')
		g->ray.x += g->ray.dir_y * 0.1;
	if (g->map[(int)(g->ray.y - g->ray.dir_x * 0.11)][(int)g->ray.x] != '1')
		g->ray.y -= g->ray.dir_x * 0.1;
	raycast(g);
}

void	move_right(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x - g->ray.dir_y * 0.11)] != '1')
		g->ray.x -= g->ray.dir_y * 0.1;
	if (g->map[(int)(g->ray.y + g->ray.dir_x * 0.11)][(int)g->ray.x] != '1')
		g->ray.y += g->ray.dir_x * 0.1;
	raycast(g);
}

void	rotate_left(t_game *g)
{
	double	old_dir_x;
	double	r;
	double	old_plane_x;

	r = 0.1;
	old_dir_x = g->ray.dir_x;
	g->ray.dir_x = g->ray.dir_x * cos(-r) - g->ray.dir_y * sin(-r);
	g->ray.dir_y = old_dir_x * sin(-r) + g->ray.dir_y * cos(-r);
	old_plane_x = g->ray.plane_x;
	g->ray.plane_x = g->ray.plane_x * cos(-r) - g->ray.plane_y * sin(-r);
	g->ray.plane_y = old_plane_x * sin(-r) + g->ray.plane_y * cos(-r);
	raycast(g);
}

void	rotate_right(t_game *g)
{
	double	old_dir_x;
	double	r;
	double	old_plane_x;

	r = 0.1;
	old_dir_x = g->ray.dir_x;
	g->ray.dir_x = (g->ray.dir_x * cos(r)) - g->ray.dir_y * sin(r);
	g->ray.dir_y = old_dir_x * sin(r) + g->ray.dir_y * cos(r);
	old_plane_x = g->ray.plane_x;
	g->ray.plane_x = (g->ray.plane_x * cos(r)) - g->ray.plane_y * sin(r);
	g->ray.plane_y = old_plane_x * sin(r) + g->ray.plane_y * cos(r);
	raycast(g);
}

// void	move_up(t_game *game)
// {
// 	// int	number;

// 	// number = (int)(game->ray.y + game->ray.delta_y)
// 	// 	* 1024 + (int)(game->ray.x + game->ray.delta_x);
// 	// if (game->img.addr[number] == PURPLE)
// 	// 	return ;
// 	//clear_player(game);
// 	game->ray.x += game->ray.delta_x;
// 	game->ray.y += game->ray.delta_y;
// 	raycast(game);
// 	//draw_player(game);
// }

// void	move_down(t_game *game)
// {
// 	// int	number;

// 	// number = (int)(game->ray.y - game->ray.delta_y)
// 	// 	* 1024 + (int)(game->ray.x - game->ray.delta_x);
// 	// if (game->img.addr[number] == PURPLE)
// 	// 	return ;
// 	//clear_player(game);
// 	game->ray.x -= game->ray.delta_x;
// 	game->ray.y -= game->ray.delta_y;
// 	raycast(game);
// 	//draw_player(game);
// }
// void	move_left(t_game *game)
// {
// 	double	number;
// 	number = (game->ray.angle -= M_PI / 20);
// 	//clear_player(game);
// 	if (number < 0)
// 		game->ray.angle += M_PI * 2;
// 	game->ray.delta_x = cos(game->ray.angle) * 5;
// 	game->ray.delta_y = sin(game->ray.angle) * 5;
// 	raycast(game);
// 	//draw_player(game);
// }

// void	move_right(t_game *game)
// {
// 	double	number;
// 	number = (game->ray.angle += M_PI / 20);
// 	//clear_player(game);
// 	if (number > 2 * M_PI)
// 		game->ray.angle -= M_PI * 2;
// 	game->ray.delta_x = cos(game->ray.angle) * 5;
// 	game->ray.delta_y = sin(game->ray.angle) * 5;
// 	raycast(game);
// 	//draw_player(game);
// }
