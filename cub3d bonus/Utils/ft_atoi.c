/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:17:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/22 14:18:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi(const char *str)
{
	int			n;
	int			negative;
	const char	*src;
	int			i;

	i = 0;
	src = str;
	while ((src[i] >= 9 && src[i] <= 13) || (src[i] == ' '))
		i++;
	negative = 0;
	if (src[i] == '-' || src[i] == '+')
		if (src[i++] == '-')
			negative = 1 - negative;
	n = 0;
	while (src[i] >= '0' && src[i] <= '9')
		n = src[i++] - '0' + n * 10;
	if (negative)
		n *= -1;
	return (n);
}
