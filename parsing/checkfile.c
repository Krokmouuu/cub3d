/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:44:46 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/02 16:47:12 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	getmap(int fd)
{
	int		i;
	char	*str;
	int		j;
	
	j = 1;
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		while (str[i] == '\t' || str[i] == ' ')
			i++;
		if (ft_strncmp(&str[i], "1", 1) == 0)
			break ;
		j++;
		free (str);
	}
	free (str);
	return (j);
}

int	checker(int fd, int len)
{
	int		check;
	int		i;
	char	*str;

	check = 0;
	i = -1;
	while (++i < len)
	{
		str = get_next_line(fd);
		if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
			check++;
		if (ft_strncmp(str, "SO ", 3) == 0 || ft_strncmp(str, "WE ", 3) == 0)
			check++;
		if (ft_strncmp(str, "F ", 2) == 0)
			check++;
		if (ft_strncmp(str, "C ", 2) == 0)
			check++;
		free (str);
	}
	if (check == 6)
		return (0);
	return (1);
}

int	checkvalid(int len, t_game *game)
{
	int	fd;

	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		error("Error File\n");
	len = getmap(fd);
	close (fd);
	printf("Len -> %d\n", len);
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		error("Error File\n");
	if (len <= 6)
		error("Wrong parameters\n");
	if (!checker(fd, len))
	{
		close (fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	checkmap(int len, t_game *game)
{
	if (checkvalid(len, game) == 1)
		error("Wrong parameters\n");
	get_texture(len, game);
	return (0);
}

int	checkfile(t_game *game)
{
	int		fd;
	int		len;
	char	buf[1];
	int		pleberr;

	if (open(game->file, O_DIRECTORY) > 0)
		error("Error File\n");
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		error("Error File\n");
	pleberr = 1;
	len = 1 ;
	buf[0] = '\0';
	while (pleberr == 1)
	{
		pleberr = read(fd, buf, 1);
		if (pleberr != 1)
			break ;
		if (buf[0] == '\n')
			len++;
	}
	close (fd);
	checkmap(len, game);
	return (0);
}
