/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/10 18:15:52 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "tuc3D");
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_loop(game->mlx);
}