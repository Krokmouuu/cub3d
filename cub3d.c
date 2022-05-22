/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:45:00 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/22 15:21:26 by bleroy           ###   ########.fr       */
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
		return (0);
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".cub") == 0)
		return (1);
	else
		return (error("Missing .cub\n"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (valid(argc, argv) == 0)
		return (0);
	if (!openmap(argv, &game))
		return (0);
	system("leaks cub3d");
	return (0);
}
