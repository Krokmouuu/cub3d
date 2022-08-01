/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:41:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/08/01 12:27:43 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	getouttab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free (tab);
}

int	checktab(char c)
{
	if (c == '\n' || c == '\0')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	checkstr(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			error("Invalid RGB HAHAHA\n");
		if (str[i] == ',')
			j++;
	}
	if (j != 2)
		return (1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == ',' && (str[i + 1] == '\n' || str[i + 1] == ' '))
			return (1);
	return (0);
}

int	load_texture(t_game *g)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	g->text.n.img = mlx_xpm_file_to_image(g->mlx,
			"./texture/wall_1.xpm", &h, &w);
	g->text.n.addr = mlx_get_data_addr(g->text.n.img,
			&g->text.n.bits,
			&g->text.n.line, &g->text.n.endian);
	g->text.s.img = mlx_xpm_file_to_image(g->mlx,
			"./texture/wall_2.xpm", &h, &w);
	g->text.s.addr = mlx_get_data_addr(g->text.s.img,
			&g->text.s.bits,
			&g->text.s.line, &g->text.s.endian);
	return (0);
}

int	load_texture_2(t_game *g)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	g->text.w.img = mlx_xpm_file_to_image(g->mlx,
			"./texture/wall_3.xpm", &h, &w);
	g->text.w.addr = mlx_get_data_addr(g->text.w.img,
			&g->text.w.bits,
			&g->text.w.line, &g->text.w.endian);
	g->text.e.img = mlx_xpm_file_to_image(g->mlx,
			"./texture/wall_4.xpm", &h, &w);
	g->text.e.addr = mlx_get_data_addr(g->text.e.img,
			&g->text.e.bits,
			&g->text.e.line, &g->text.e.endian);
	return (0);
}
