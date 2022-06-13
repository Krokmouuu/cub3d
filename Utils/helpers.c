/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:04:13 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/13 17:09:02 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	helper_nul(t_game *game, int y, int x)
{
	if ((game->map[y][x] == '0') &&
				(ft_strlen(game->map[y - 1]) < ft_strlen(game->map[y])
				|| ft_strlen(game->map[y + 1]) < ft_strlen(game->map[y])))
		error("Invalid map\n");
}