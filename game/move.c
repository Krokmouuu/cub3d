/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:17:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/21 18:40:42 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clearline(t_game *game, int px, int py, int endofX, int endofY)
{
	int	delta_x;
	int	delta_y;
	int	slope_x;
	int	slope_y;
	int	error;
	int	e2;

	delta_x = abs(endofX - px);
	delta_y = abs(endofY - py);
	slope_x = -1;
	slope_y = -1;
	error = -delta_y / 2;
	e2 = 0;
	if (delta_x > delta_y)
		error = delta_x / 2;
	if (px < endofX)
		slope_x = 1;
	if (py < endofY)
		slope_y = 1;
	while (1)
	{
		if (px == endofX && py == endofY)
			break ;
		if (game->images.addr[py * 1024 + px] == SQUARE)
			game->images.addr[py * 1024 + px] = SQUARE;
		else
			game->images.addr[py * 1024 + px] = PINK;
		e2 = error;
		if (e2 > -delta_x)
		{
			error -= delta_y;
			px += slope_x;
		}
		if (e2 < delta_y)
		{
			error += delta_x;
			py += slope_y;
		}
	}
}

void	drawline(t_game *game, int px, int py, int endofX, int endofY)
{
	int	delta_x;
	int	delta_y;
	int	slope_x;
	int	slope_y;
	int	error;
	int	e2;

	delta_x = abs(endofX - px);
	delta_y = abs(endofY - py);
	slope_x = -1;
	slope_y = -1;
	error = -delta_y / 2;
	e2 = 0;
	if (delta_x > delta_y)
		error = delta_x / 2;
	if (px < endofX)
		slope_x = 1;
	if (py < endofY)
		slope_y = 1;
	while (1)
	{
		if (px == endofX && py == endofY)
			break ;
		if (game->images.addr[py * 1024 + px] == SQUARE)
			game->images.addr[py * 1024 + px] = SQUARE;
		else
			game->images.addr[py * 1024 + px] = GREEN;
		e2 = error;
		if (e2 > -delta_x)
		{
			error -= delta_y;
			px += slope_x;
		}
		if (e2 < delta_y)
		{
			error += delta_x;
			py += slope_y;
		}
	}
}

void	clear_player(t_game *game)
{
	double	max_y;
	double	max_x;
	double	temp_x;
	double	temp_y;

	temp_x = game->ray.x;
	temp_y = game->ray.y;
	max_y = temp_y + 5;
	max_x = temp_x + 5;
	while (temp_y < max_y)
	{
		while (temp_x < max_x)
		{
			if (game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x - 2)] == SQUARE)
				game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x++ - 2)] = SQUARE;
			else if (game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x - 2)] != SQUARE)
				game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x++ - 2)] = PINK;
		}
		temp_x = max_x - 5;
		temp_y++;
	}
	clearcast(game);
}

void	draw_player(t_game *game)
{
	double	max_y;
	double	max_x;
	double	temp_x;
	double	temp_y;

	temp_x = game->ray.x;
	temp_y = game->ray.y;
	max_y = temp_y + 5;
	max_x = temp_x + 5;
	while (temp_y  < max_y)
	{
		while (temp_x < max_x)
			if (game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x - 2)] == SQUARE)
				game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x++ - 2)] = SQUARE;
			else if (game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x - 2)] != SQUARE)
				game->images.addr[(int)(temp_y - 2) * 1024 + (int)(temp_x++ - 2)] = GREEN;
		temp_x = max_x - 5;
		temp_y++;
	}
	raycast(game);
}

int	move(int key, t_game *game)
{
	printf("Player X: %d Player Y: %d\n", (int)game->ray.x, (int)game->ray.y);
	if (key == UP)
	{
		if (game->images.addr[(int)(game->ray.y + game->ray.delta_y) * 1024 + (int)(game->ray.x + game->ray.delta_x)] == PURPLE)
			return (1);
		clear_player(game);
		game->ray.x += game->ray.delta_x;
		game->ray.y += game->ray.delta_y;
		draw_player(game);
	}
	if (key == DOWN)
	{
		if (game->images.addr[(int)(game->ray.y - game->ray.delta_y) * 1024 + (int)(game->ray.x - game->ray.delta_x)] == PURPLE)
			return (1);
		clear_player(game);
		game->ray.x -= game->ray.delta_x;
		game->ray.y -= game->ray.delta_y;
		draw_player(game);
	}
	if (key == LEFT)
	{
		clear_player(game);
		if ((game->ray.angle -= M_PI / 20) < 0)
        	game->ray.angle += M_PI * 2;
		game->ray.delta_x = cos(game->ray.angle) * 5;
		game->ray.delta_y = sin(game->ray.angle) * 5;
		draw_player(game);
	}
	if (key == RIGHT)
	{
		clear_player(game);
        if ((game->ray.angle += M_PI / 20) > 2 * M_PI)
        	game->ray.angle -= M_PI * 2;
		game->ray.delta_x = cos(game->ray.angle) * 5;
		game->ray.delta_y = sin(game->ray.angle) * 5;
		draw_player(game);
	}
	return (0);
}
