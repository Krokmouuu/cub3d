/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startcub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:21:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/18 13:34:55 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_direction(t_game *g)
{
	double	old_dir_x;
	double	r;
	double	old_plane_x;

	r = 0;
	if (g->player.direction == 'N')
		r = 1.5;
	else if (g->player.direction == 'S')
		r = -1.5;
	else if (g->player.direction == 'W')
		r = 3.2;
	else if (g->player.direction == 'E')
		return ;
	old_dir_x = g->ray.dir_x;
	g->ray.dir_x = g->ray.dir_x * cos(-r) - g->ray.dir_y * sin(-r);
	g->ray.dir_y = old_dir_x * sin(-r) + g->ray.dir_y * cos(-r);
	old_plane_x = g->ray.plane_x;
	g->ray.plane_x = g->ray.plane_x * cos(-r) - g->ray.plane_y * sin(-r);
	g->ray.plane_y = old_plane_x * sin(-r) + g->ray.plane_y * cos(-r);
}

void	start_check_map(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 640, 480);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits, &game->img.line, &game->img.endian);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	start(t_game *game)
{
	start_check_map(game);
	mlx_mouse_hide();
	mlx_hook(game->win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 0, closed, game);
	mlx_hook(game->win, 4, 1L << 8, uwu, game); 
	mlx_loop(game->mlx);
}
