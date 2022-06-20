#include "../cub3d.h"

void	clearline(t_game *game, int player_x, int player_y, int endofX, int endofY)
{
	int	delta_x;
	int	delta_y;
	int	slope_x;
	int	slope_y;
	int	error;
	int	e2;

	delta_x = abs(endofX - player_x);
	delta_y = abs(endofY - player_y);
	slope_x = -1;
	slope_y = -1;
	error = -delta_y / 2;
	e2 = 0;
	if (delta_x > delta_y)
		error = delta_x / 2;
	if (player_x < endofX)
		slope_x = 1;
	if (player_y < endofY)
		slope_y = 1;
	while (1)
	{
		if (player_x == endofX && player_y == endofY)
			break ;
		if (game->images.addr[player_y * 1024 + player_x] == RED)
			break ;
		game->images.addr[player_y * 1024 + player_x] = GREEN;
		e2 = error;
		if (e2 > -delta_x)
		{
			error -= delta_y;
			player_x += slope_x;
		}
		if (e2 < delta_y)
		{
			error += delta_x;
			player_y += slope_y;
		}
	}
}

void	drawline(t_game *game, int player_x, int player_y, int endofX, int endofY)
{
	int	delta_x;
	int	delta_y;
	int	slope_x;
	int	slope_y;
	int	error;
	int	e2;

	delta_x = abs(endofX - player_x);
	delta_y = abs(endofY - player_y);
	slope_x = -1;
	slope_y = -1;
	error = -delta_y / 2;
	e2 = 0;
	if (delta_x > delta_y)
		error = delta_x / 2;
	if (player_x < endofX)
		slope_x = 1;
	if (player_y < endofY)
		slope_y = 1;
	while (1)
	{
		if (player_x == endofX && player_y == endofY)
			break ;
		if (game->images.addr[player_y * 1024 + player_x] == RED)
			break ;
		game->images.addr[player_y * 1024 + player_x] = WHITE;
		e2 = error;
		if (e2 > -delta_x)
		{
			error -= delta_y;
			player_x += slope_x;
		}
		if (e2 < delta_y)
		{
			error += delta_x;
			player_y += slope_y;
		}
	}
}

void	clear_player(t_game *game, double delta_x, double delta_y)
{
	double	max_y;
	double	max_x;
	double	temp_x;
	double	temp_y;

	temp_x = game->player.x;
	temp_y = game->player.y;
	max_y = temp_y + 5;
	max_x = temp_x + 5;
	while (temp_y < max_y)
	{
		while (temp_x < max_x)
			game->images.addr[(int)temp_y * 1024 + (int)temp_x++] = GREEN;
		temp_x = max_x - 5;
		temp_y++;
	}
	clearline(game, game->player.x, game->player.y, game->player.x + (delta_x * 5), game->player.y + (delta_y * 5));
}

void	draw_player(t_game *game, double delta_x, double delta_y)
{
	double	max_y;
	double	max_x;
	double	temp_x;
	double	temp_y;

	temp_x = game->player.x;
	temp_y = game->player.y;
	max_y = temp_y + 5;
	max_x = temp_x + 5;
	while (temp_y < max_y)
	{
		while (temp_x < max_x)
			game->images.addr[(int)temp_y * 1024 + (int)temp_x++] = WHITE;
		temp_x = max_x - 5;
		temp_y++;
	}
	drawline(game, game->player.x, game->player.y, game->player.x + (delta_x * 5), game->player.y + (delta_y * 5));
}

int	move(int key, t_game *game)
{
	printf("Player X: %d PLayer Y: %d\n", (int)game->player.x, (int)game->player.y);
	if (key == UP)
	{
		if (game->images.addr[(int)(game->player.y + game->player.delta_y) * 1024 + (int)(game->player.x + game->player.delta_x)] == RED)
			return (1);
		clear_player(game, game->player.delta_x, game->player.delta_y);
		game->player.x += game->player.delta_x;
		game->player.y += game->player.delta_y;
		draw_player(game, game->player.delta_x, game->player.delta_y);
	}
	if (key == DOWN)
	{
		if (game->images.addr[(int)(game->player.y - game->player.delta_y) * 1024 + (int)(game->player.x - game->player.delta_x)] == RED)
			return (1);
		clear_player(game, game->player.delta_x, game->player.delta_y);
		game->player.x -= game->player.delta_x;
		game->player.y -= game->player.delta_y;
		draw_player(game, game->player.delta_x, game->player.delta_y);
	}
	if (key == LEFT)
	{
		clear_player(game, game->player.delta_x, game->player.delta_y);
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		game->player.delta_x = cos(game->player.angle) * 5;
		game->player.delta_y = sin(game->player.angle) * 5;
		draw_player(game, game->player.delta_x, game->player.delta_y);
	}
	if (key == RIGHT)
	{
		clear_player(game, game->player.delta_x, game->player.delta_y);
		game->player.angle += 0.1;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
		game->player.delta_x = cos(game->player.angle) * 5;
		game->player.delta_y = sin(game->player.angle) * 5;
		draw_player(game, game->player.delta_x, game->player.delta_y);
	}
	return (0);
}
