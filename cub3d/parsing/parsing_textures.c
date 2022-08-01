/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:20:49 by bleroy            #+#    #+#             */
/*   Updated: 2022/08/01 15:08:26 by bleroy           ###   ########.fr       */
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
	int		check;
	int		*tablo;

	i = 1;
	tablo = malloc((3) * sizeof(int));
	while (str[i] && str[i] == ' ')
		i++;
	if (checkstr(&str[i]) == 1)
		error("Wrong RGB values\n");
	tab = ft_split(&str[i], ',');
	i = -1;
	while (tab[++i])
	{
		check = -1;
		while (tab[i][++check])
			if (tab[i][check] == ' ' || checktab(tab[i][check]) == 1)
				error("Wrong RGB values\n");
	}
	tablo[0] = ft_atoi(tab[0]);
	tablo[1] = ft_atoi(tab[1]);
	tablo[2] = ft_atoi(tab[2]);
	getouttab(tab);
	return (tablo);
}

void	get_texture3(char *str, t_game *game)
{
	if (str == NULL)
		error("Invalid map\n");
	if (ft_strncmp(str, "NO ", 3) == 0)
		game->text.north = get_texture_2(str);
	if (ft_strncmp(str, "EA ", 3) == 0)
		game->text.east = get_texture_2(str);
	if (ft_strncmp(str, "WE ", 3) == 0)
		game->text.west = get_texture_2(str);
	if (ft_strncmp(str, "SO ", 3) == 0)
		game->text.south = get_texture_2(str);
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
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	newstr = ft_strdup(&str[i]);
	j = ft_strlen(newstr);
	if (j < 5)
		error("Error texture\n");
	j -= 5;
	if (ft_strcmp(&newstr[j], ".xpm\n") != 0)
	{
		free (newstr);
		return (NULL);
	}
	return (newstr);
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
		free (str);
	}
	close(fd);
	if (game->text.north == NULL || game->text.east == NULL
		|| game->text.west == NULL || game->text.south == NULL)
		error("Invalid texture\n");
	if (game->text.ceiling == NULL || game->text.floor == NULL)
		error("Missing RGB values\n");
}
