/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:06:12 by ple-berr          #+#    #+#             */
/*   Updated: 2022/06/28 16:06:13 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	define_delta(double rayDir)
{
	if (rayDir == 0)
		return (1e30);
	return (fabs(1 / rayDir));
}

double	define_dist(double rayDir, double ray, double map, double deltaDist)
{
	double	result;

	if (rayDir < 0)
	{
		result = ((ray - map) * deltaDist);
		return (result);
	}
	result = ((map + 1.0 - ray) * deltaDist);
	return (result);
}

double	define_step(double rayDir)
{
	if (rayDir < 0)
		return (-1.0);
	return (1);
}
