/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:45:00 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/08 18:16:51 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit (0);
}

int	valid(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		error("Missing map\n");
	else if (argc > 2)
		error("Too many args\n");
	i = ft_strlen(argv[1]);
	if (i < 4)
		error("Invalid map\n");
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".cub") == 0)
		return (1);
	else
		return (error("Missing .cub\n"));
}

int	main(int argc, char **argv)
{
	t_game	game;

	valid(argc, argv);
	openmap(argv, &game);
	parsing_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1024, 512, "tuc3D");
//	start_check_map(&game);
//	start(&game);
	return (0);
}

/*

void	clearcast(t_game *game)
{
	double player_x = game->ray.x;
	double player_y = game->ray.y;
	double	vector_y;
	double	vector_x;
	double	temp_x;
	double	intersection_y;
	double	intersection_x;
	double	c_y;
	double	c_x;
	double angle = game->ray.angle;
	// on reset l'angle pour faire proprement un tour sur soi meme tu connais bref
	if (angle > 0 && angle < M_PI)
	{
		//intersection y quand le rayon touche une ligne horizontale de la carte
		intersection_y = floor(player_y / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE;
		//vector y c'est la distance en Y que notre rayon va parcourir à chaque itération depuis l'intersection y
		vector_y = SQUARE_SIZE;
		//angle = game->ray.angle -= M_PI * 2;
		// ici on regarde vers le bas -> on avance vers les Y positifs
	}
	else
	{
		// à l'inverse ici on va vers le haut du coup on va vers les Y négatifs
		intersection_y = floor(player_y / SQUARE_SIZE) * SQUARE_SIZE - 1;
		vector_y = -SQUARE_SIZE;
	}
	vector_x = SQUARE_SIZE / tan(angle);
	temp_x = tan(angle) * intersection_y - player_y;
	intersection_x = player_x + (player_y - intersection_y) / tan(angle);
	c_x = intersection_x + vector_x;
	c_y = intersection_y + vector_y;
	int x = (int)c_x / SQUARE_SIZE;
	int y = (int)c_y / SQUARE_SIZE;
	while (1)
	{
		if (x >= game->x || y >= game->y || x < 0 || y < 0)
			break ;
		if (game->map[y][x] != '0')
			break ;
		c_x += vector_x;
		c_y += vector_y;
		x = (int)c_x / SQUARE_SIZE;
		y = (int)c_y / SQUARE_SIZE;
	}
	printf("angle %f,intersection y %f,intersection x %f\n", angle, c_y, c_x);
	//game->ray.touch_y = c_y;
	//game->ray.touch_x = c_x;
	clearline(game, game->ray.x, game->ray.y, c_x, c_y);
	//draw_wall(game, intersection_x, intersection_y, angle);
}

void	raycast(t_game *game)
{
	double player_x = game->ray.x;
	double player_y = game->ray.y;
	double	vector_y;
	double	vector_x;
	double	temp_x;
	double	intersection_y;
	double	intersection_x;
	double	c_y;
	double	c_x;
	double angle = game->ray.angle;
	// on reset l'angle pour faire proprement un tour sur soi meme tu connais bref
	if (angle > 0 && angle < M_PI)
	{
		//intersection y quand le rayon touche une ligne horizontale de la carte
		intersection_y = floor(player_y / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE;
		//vector y c'est la distance en Y que notre rayon va parcourir à chaque itération depuis l'intersection y
		vector_y = SQUARE_SIZE;
		//ici on regarde vers le bas -> on avance vers les Y positifs
	}
	else
	{
		printf("coucou\n");
		// à l'inverse ici on va vers le haut du coup on va vers les Y négatifs
		intersection_y = floor(player_y / SQUARE_SIZE) * SQUARE_SIZE - 1;
		vector_y = -SQUARE_SIZE;
	}
	vector_x = SQUARE_SIZE / tan(angle);
	temp_x = tan(angle) * intersection_y - player_y;
	intersection_x = player_x + (player_y - intersection_y) / tan(angle);
	c_x = intersection_x + vector_x;
	c_y = intersection_y + vector_y;
	int x = (int)c_x / SQUARE_SIZE;
	int y = (int)c_y / SQUARE_SIZE;
	while (1)
	{
		if (x >= game->x || y >= game->y || x < 0 || y < 0)
			break ;
		if (game->map[y][x] != '0')
			break ;
		c_x += vector_x;
		c_y += vector_y;
		x = (int)c_x / SQUARE_SIZE;
		y = (int)c_y / SQUARE_SIZE;
	}
	printf("angle %f,intersection y %f,intersection x %f\n", angle, c_y, c_x);
	game->ray.touch_y = c_y;
	game->ray.touch_x = c_x;
	drawline(game, game->ray.x, game->ray.y, c_x, c_y);
	//draw_wall(game, intersection_x, intersection_y, angle);
}
*/