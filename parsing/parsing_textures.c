/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:20:49 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/22 16:21:19 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	checkvalue(int *tab)
{
	int	r;
	int	g;
	int	b;

	r = tab[0];
	g = tab[1];
	b = tab[2];
	if (r > 255 || g > 255 || b > 255)
		return (0);
	return (1);
}

int	*get_color(char *str)
{
	int		i;
	char	**tab;
	int		j;
	int		*tabint;
	int		check;

	i = 1;
	j = 0;
	tabint = malloc(sizeof(int *));
	while (str[i] && str[i] == ' ')
		i++;
	tab = ft_split(&str[i], ',');
	while (tab[j])
	{
		check = 0;
		while (tab[j][check])
		{
			if (tab[j][check] == ' ' || alpha(tab[j][check]) == 1 || j >= 3)
				error("Wrong RGB values\n");
			check++;
		}
		tabint[j] = ft_atoi(tab[j]);
		j++;
	}
	return (tabint);
}

void	get_texture3(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "NO ", 3) == 0)
		game->text.n = get_texture_2(str);
	if (ft_strncmp(str, "EA ", 3) == 0)
		game->text.e = get_texture_2(str);
	if (ft_strncmp(str, "WE ", 3) == 0)
		game->text.w = get_texture_2(str);
	if (ft_strncmp(str, "SO ", 3) == 0)
		game->text.s = get_texture_2(str);
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		game->text.floor = get_color(str);
		if (checkvalue(game->text.floor) == 0)
			error("Wrong RGB values\n");
	}
	if (ft_strncmp(str, "C ", 2) == 0)
	{
		game->text.ceiling = get_color(str);
		if (checkvalue(game->text.ceiling) == 0)
			error("Wrong RGB values\n");
	}
}

char	*get_texture_2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	return (ft_strdup(&str[i]));
}

void	get_texture(int len, t_game *game)
{
	char	*str;
	int		fd;
	int		i;

	i = -1;
	if (open(game->file, 0x100000) > 0)
		error("Error File\n");
	fd = open(game->file, 0x0000);
	if (fd < 0)
		error("Error File\n");
	while (++i < len)
	{
		str = get_next_line(fd);
		get_texture3(str, game);
	}
	close(fd);
	if (game->text.n == NULL || game->text.e == NULL
		|| game->text.w == NULL || game->text.s == NULL)
		error("Invalid texture\n");
	if (game->text.ceiling == NULL || game->text.floor == NULL)
		error("Missing RGB values\n");
}
