/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:05:51 by ple-berr          #+#    #+#             */
/*   Updated: 2022/07/30 18:24:48 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x + g->ray.dir_x * 0.2)] != '1')
		g->ray.x += g->ray.dir_x * 0.2;
	if (g->map[(int)(g->ray.y + g->ray.dir_y * 0.2)][(int)g->ray.x] != '1')
		g->ray.y += g->ray.dir_y * 0.2;
	raycast(g);
}

void	move_down(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x - g->ray.dir_x * 0.2)] != '1')
		g->ray.x -= g->ray.dir_x * 0.2;
	if (g->map[(int)(g->ray.y - g->ray.dir_y * 0.2)][(int)g->ray.x] != '1')
		g->ray.y -= g->ray.dir_y * 0.2;
	raycast(g);
}

void	move_left(t_game *g)
{	
	if (g->map[(int)g->ray.y][(int)(g->ray.x + g->ray.dir_y * 0.21)] != '1')
		g->ray.x += g->ray.dir_y * 0.2;
	if (g->map[(int)(g->ray.y - g->ray.dir_x * 0.21)][(int)g->ray.x] != '1')
		g->ray.y -= g->ray.dir_x * 0.2;
	raycast(g);
}

void	move_right(t_game *g)
{
	if (g->map[(int)g->ray.y][(int)(g->ray.x - g->ray.dir_y * 0.21)] != '1')
		g->ray.x -= g->ray.dir_y * 0.2;
	if (g->map[(int)(g->ray.y + g->ray.dir_x * 0.21)][(int)g->ray.x] != '1')
		g->ray.y += g->ray.dir_x * 0.2;
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
