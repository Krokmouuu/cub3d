/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:45:00 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/30 11:29:34 by ple-berr         ###   ########.fr       */
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
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "tuc3D");
	load_texture(&game);
	load_texture_2(&game);
	openmap(argv, &game);
	parsing_map(&game);
	start_check_map(&game);
	start(&game);
	return (0);
}