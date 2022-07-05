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

int	move(int key, t_game *game)
{
	if (key == UP)
		move_up(game);
	if (key == DOWN)
		move_down(game);
	if (key == LEFT)
		move_left(game);
	if (key == RIGHT)
		move_right(game);
	return (0);
}

// void	clear_player(t_game *g)
// {
// 	double	max_y;
// 	double	max_x;
// 	double	t_x;
// 	double	t_y;

// 	t_x = g->ray.x;
// 	t_y = g->ray.y;
// 	max_y = t_y + 5;
// 	max_x = t_x + 5;
// 	while (t_y < max_y)
// 	{
// 		while (t_x < max_x)
// 		{
// 			if (g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x - 2)] == SQR)
// 				g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x++ - 2)] = SQR;
// 			else if (g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x - 2)] != SQR)
// 				g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x++ - 2)] = PINK;
// 		}
// 		t_x = max_x - 5;
// 		t_y++;
// 	}
// 	//clearcast(g);
// }

// void	draw_player(t_game *g)
// {
// 	double	max_y;
// 	double	max_x;
// 	double	t_x;
// 	double	t_y;

// 	t_x = g->ray.x;
// 	t_y = g->ray.y;
// 	max_y = t_y + 5;
// 	max_x = t_x + 5;
// 	while (t_y < max_y)
// 	{
// 		while (t_x < max_x)
// 		{
// 			if (g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x - 2)] == SQR)
// 				g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x++ - 2)] = SQR;
// 			else if (g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x - 2)] != SQR)
// 				g->img.addr[(int)(t_y - 2) * 1024 + (int)(t_x++ - 2)] = GREEN;
// 		}
// 		t_x = max_x - 5;
// 		t_y++;
// 	}
// 	raycast(g);
// }

// void	clearline(t_game *game, int px, int py, int endofX, int endofY)
// {
// 	int	delta_x;
// 	int	delta_y;
// 	int	slope_x;
// 	int	slope_y;
// 	int	error;
// 	int	e2;

// 	delta_x = abs(endofX - px);
// 	delta_y = abs(endofY - py);
// 	slope_x = -1;
// 	slope_y = -1;
// 	error = -delta_y / 2;
// 	e2 = 0;
// 	if (delta_x > delta_y)
// 		error = delta_x / 2;
// 	if (px < endofX)
// 		slope_x = 1;
// 	if (py < endofY)
// 		slope_y = 1;
// 	while (1)
// 	{
// 		if (px == endofX && py == endofY)
// 			break ;
// 		if (game->img.addr[py * 1024 + px] == SQR)
// 			game->img.addr[py * 1024 + px] = SQR;
// 		else
// 			game->img.addr[py * 1024 + px] = PINK;
// 		e2 = error;
// 		if (e2 > -delta_x)
// 		{
// 			error -= delta_y;
// 			px += slope_x;
// 		}
// 		if (e2 < delta_y)
// 		{
// 			error += delta_x;
// 			py += slope_y;
// 		}
// 	}
// }

// void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = game->img.addr + (y * game->img.line + x * (game->img.bits / 8));
// 	*(unsigned int*)dst = color;
// }


// void	drawline(t_game *game, int px, int py, int endofX, int endofY)
// {
// 	int	delta_x;
// 	int	delta_y;
// 	int	slope_x;
// 	int	slope_y;
// 	int	error;
// 	int	e2;

// 	delta_x = abs(endofX - px);
// 	delta_y = abs(endofY - py);
// 	slope_x = -1;
// 	slope_y = -1;
// 	error = -delta_y / 2;
// 	e2 = 0;
// 	if (delta_x > delta_y)
// 		error = delta_x / 2;
// 	if (px < endofX)
// 		slope_x = 1;
// 	if (py < endofY)
// 		slope_y = 1;
// 	while (1)
// 	{
// 		(void)game;
// 		printf("couycou\n");
// 		//if (px == endofX && py == endofY)
// 		// 	break ;
// 		// if (game->img.addr[py * 1024 + px] == SQR)
// 		// 	game->img.addr[py * 1024 + px] = SQR;
// 		// else
// 		// 	game->img.addr[py * 1024 + px] = GREEN;
// 		e2 = error;
// 		if (e2 > -delta_x)
// 		{
// 			error -= delta_y;
// 			px += slope_x;
// 		}
// 		if (e2 < delta_y)
// 		{
// 			error += delta_x;
// 			py += slope_y;
// 		}
// 	}
// }