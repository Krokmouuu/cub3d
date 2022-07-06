/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:05:51 by ple-berr          #+#    #+#             */
/*   Updated: 2022/06/29 17:05:52 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_game *game)
{
	if (game->map[(int)game->ray.y][(int)(game->ray.x + game->ray.dir_x * 0.1)] != '1')
		game->ray.x += game->ray.dir_x * 0.1;
	if (game->map[(int)(game->ray.y + game->ray.dir_y * 0.1)][(int)game->ray.x] != '1')	
		game->ray.y += game->ray.dir_y * 0.1;
	raycast(game);
}

void	move_down(t_game *game)
{
	if (game->map[(int)game->ray.y][(int)(game->ray.x - game->ray.dir_x)] != '1')	
		game->ray.x -= game->ray.dir_x * 0.1;
	if (game->map[(int)(game->ray.y - game->ray.dir_y)][(int)game->ray.x] != '1')	
		game->ray.y -= game->ray.dir_y * 0.1;
	raycast(game);
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

void	move_left(t_game *game)
{
	double	old_dir_x;
	double	rotspeed = 0.2;
	double	old_plane_x;

	old_dir_x = game->ray.dir_x;
	game->ray.dir_x = game->ray.dir_x * cos(-rotspeed) - game->ray.dir_y * sin(-rotspeed);
	game->ray.dir_y = old_dir_x * sin(-rotspeed) + game->ray.dir_y * cos(-rotspeed);
	old_plane_x = game->ray.plane_x;
	game->ray.plane_x = game->ray.plane_x * cos(-rotspeed) - game->ray.plane_y * sin(-rotspeed);
	game->ray.plane_y = old_plane_x * sin(-rotspeed) + game->ray.plane_y * cos(-rotspeed);
	raycast(game);
}

void	move_right(t_game *game)
{
	double	old_dir_x;
	double	rotspeed = 0.2;
	double	old_plane_x;

	old_dir_x = game->ray.dir_x;
	game->ray.dir_x = (game->ray.dir_x * cos(rotspeed)) - game->ray.dir_y * sin(rotspeed);
	game->ray.dir_y = old_dir_x * sin(rotspeed) + game->ray.dir_y * cos(rotspeed);
	old_plane_x = game->ray.plane_x;
	game->ray.plane_x = (game->ray.plane_x * cos(rotspeed)) - game->ray.plane_y * sin(rotspeed);
	game->ray.plane_y = old_plane_x * sin(rotspeed) + game->ray.plane_y * cos(rotspeed);
	raycast(game);
}

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
