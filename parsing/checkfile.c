/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:44:46 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/22 18:55:05 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	getmap(int fd)
{
	int		i;
	char	*str;

	i = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (ft_strncmp(str, "1111", 4) == 0)
			break ;
		i++;
	}
	return (i);
}

int	checker(int fd, int len)
{
	int		check;
	int		i;
	char	*str;

	check = 0;
	i = -1;
	while (++i < len - 1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
			check++;
		if (ft_strncmp(str, "SO ", 3) == 0 || ft_strncmp(str, "WE ", 3) == 0)
			check++;
		if (ft_strncmp(str, "F ", 2) == 0)
			check++;
		if (ft_strncmp(str, "C ", 2) == 0)
			check++;
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
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		error("Error File\n");
	if (len <= 6)
		error("Wrong parameters\n");
	if (checker(fd, len) == 0)
	{
		close (fd);
		return (0);
	}
	close (fd);
	return (1);
}
