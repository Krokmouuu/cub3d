/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:39:38 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 11:39:54 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_vector_x(t_game *game, double x, double y)
{
	double temp_x;
	double temp_y;

	temp_x = x;
	temp_y = y + 2;
	while (game->images.addr[(int)temp_y * 1920 + (int)temp_x] == WHITE)
		game->images.addr[(int)temp_y * 1920 + (int)temp_x++] = GREEN;
}

void	clear_vector_y(t_game *game, double x, double y)
{
	double temp_x;
	double temp_y;

	temp_x = x;
	temp_y = y + 2;
	while (game->images.addr[(int)temp_y * 1920 + (int)temp_x] == WHITE)
		game->images.addr[(int)temp_y-- * 1920 + (int)temp_x] = GREEN;
}

void	draw_vector_x(t_game *game, double x, double y)
{
	double temp_x;
	double temp_y;

	temp_x = x;
	temp_y = y + 2;
	while (game->images.addr[(int)temp_y * 1920 + (int)temp_x] != RED)
		game->images.addr[(int)temp_y * 1920 + (int)temp_x++] = WHITE;
}

void	draw_vector_y(t_game *game, double x, double y)
{
	double temp_x;
	double temp_y;

	temp_x = x;
	temp_y = y;
	while (game->images.addr[(int)temp_y * 1920 + (int)temp_x] == GREEN)
		game->images.addr[(int)temp_y-- * 1920 + (int)temp_x] = WHITE;
}

void	clear_player(t_game *game, double x, double y)
{
	double max_y;
	double max_x;

	max_y = y + 4;
	max_x = x + 4;

	//draw_cube(t_game game, (int)y, (int)x, 2);
	clear_vector_y(game, x ,y);
	clear_vector_x(game, x ,y);
	while (y < max_y)
	{
		while (x < max_x)
		{
			game->images.addr[(int)y * 1920 + (int)x++] = GREEN;
		}
		x = max_x - 4;
		y++;
	}
	//game->images.addr[(int)y * 1920 + (int)x] = GREEN;

}

void	draw_player(t_game *game, double x, double y, int i)
{
	//draw_cube(game, (int)y, (int)x, 2);
	double max_y;
	double max_x;
	double	temp_x;
	double	temp_y;

	temp_x = x;
	temp_y = y;
	max_y = y + 4;
	max_x = x + 4;
	while (y <= max_y)
	{
		while (x <= max_x)
		{
			if (game->images.addr[(int)y * 1920 + (int)x++] == RED)
				return ;
		}
		x = max_x - 4;
		y++;
	}
	x = temp_x;
	y = temp_y;
	mlx_clear_window(game->mlx, game->win);
	game->player.y = y;
	game->player.x = x;
	if (i == 1)
		clear_player(game, game->player.x, game->player.y + 4);
	else if (i == 2)
		clear_player(game, game->player.x, game->player.y - 4);
	else if (i == 3)
		clear_player(game, game->player.x + 4, game->player.y);
	else if (i == 4)
		clear_player(game, game->player.x - 4, game->player.y);
	else if (i == 0)
		clear_player(game, game->player.x - 4, game->player.y);
	draw_vector_x(game, x ,y);
	draw_vector_y(game, x ,y);
	while (y < max_y)
	{
		while (x < max_x)
		{
			game->images.addr[(int)y * 1920 + (int)x++] = WHITE;
		}
		x = max_x - 4;
		y++;
	}
}

int	move(int key, t_game *game)
{
	if (key == UP)
	{
		// if (game->map[game->player.y - 1][game->player.x] == '1')
		// 	return (0);
		//game->map[game->player.y][game->player.x] = '0';
		draw_player(game, game->player.x, game->player.y - 4, 1);
	}
	if (key == DOWN)
	{
		// if (game->map[game->player.y + 1][game->player.x] == '1')
		// 	return (0);
		//game->map[game->player.y][game->player.x] = '0';
		//game->map[game->player.y + 1][game->player.x] = 'N';
		//game->player.y = game->player.y + 1;
		// mlx_clear_window(game->mlx, game->win);
		// clear_player(game, game->player.x, game->player.y - 1);
		draw_player(game, game->player.x, game->player.y + 4, 2);
		//mlx_clear_window(game->mlx, game->win);
	}
	if (key == LEFT)
	{
		// if (game->map[game->player.y][game->player.x - 1] == '1')
		// 	return (0);
		//game->map[game->player.y][game->player.x] = '0';
		//game->map[game->player.y][game->player.x - 1] = 'N';
		//game->player.x = game->player.x - 1;
		// mlx_clear_window(game->mlx, game->win);
		// clear_player(game, game->player.x + 1, game->player.y);
		//mlx_clear_window(game->mlx, game->win);
		draw_player(game, game->player.x - 4, game->player.y, 3);
	}
	if (key == RIGHT)
	{
		// if (game->map[game->player.y][game->player.x +1] == '1')
		// 	return (0);
		//game->map[game->player.y][game->player.x] = '0';
		//game->map[game->player.y][game->player.x + 1] = 'N';
		//game->player.x = game->player.x + 1;
		// mlx_clear_window(game->mlx, game->win);
		// clear_player(game, game->player.x - 1, game->player.y);
		//mlx_clear_window(game->mlx, game->win);
		draw_player(game, game->player.x + 4, game->player.y, 4);
	}
	//mlx_put_image_to_window(game->mlx, game->win, game->images.img, 100, 100);
	return (0);
}

int	keypressed(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		error("Game Closed !\n");
	}
	else if (key == UP || key == LEFT || key == RIGHT || key == DOWN
	|| key == LEFT_ARROW || key == RIGHT_ARROW)
		move(key, game);
	mlx_put_image_to_window(game->mlx, game->win, game->images.img, 100, 100);
	return (0);
}

int	closed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game Closed !\n");
	exit (0);
}
