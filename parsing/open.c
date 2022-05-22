/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:38:35 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/22 18:42:22 by bleroy           ###   ########.fr       */
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

int	openmap(char **argv, t_game *game)
{
	init(game, argv);
	if (checkfile(game) == 0)
		return (0);
	return (0);
}
