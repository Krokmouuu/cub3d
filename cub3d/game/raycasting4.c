/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:01:07 by ple-berr          #+#    #+#             */
/*   Updated: 2022/08/01 12:26:11 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	choose_texture(t_game *g, int side)
{
	unsigned int	c;

	c = 0;
	if (side == 0)
	{
		if (g->ray.step_x <= 0)
			c = get_data_color(g->ray.tex_x, g->ray.tex_y,
					g->text.n.addr, &g->text.n);
		if (g->ray.step_x > 0)
			c = get_data_color(g->ray.tex_x, g->ray.tex_y,
					g->text.s.addr, &g->text.s);
	}
	if (side == 1)
	{
		if (g->ray.step_y <= 0)
			c = get_data_color(g->ray.tex_x, g->ray.tex_y,
					g->text.w.addr, &g->text.w);
		if (g->ray.step_y > 0)
			c = get_data_color(g->ray.tex_x, g->ray.tex_y,
					g->text.e.addr, &g->text.e);
	}
	return (c);
}
