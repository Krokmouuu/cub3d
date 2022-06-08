/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:45:00 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/08 17:50:12 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
//	system("leaks cub3d");
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
//	system("leaks cub3d");
	return (0);
}
