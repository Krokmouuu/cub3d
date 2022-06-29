/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:38:35 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 18:37:13 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_game *game, char **argv)
{
	game->file = argv[1];
	game->x = 0;
	game->y = 0;
	game->text.n = NULL;
	game->text.e = NULL;
	game->text.s = NULL;
	game->text.w = NULL;
	game->text.floor = NULL;
	game->text.ceiling = NULL;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
}

int	openmap(char **argv, t_game *game)
{
	init(game, argv);
	checkfile(game);
	return (0);
}
