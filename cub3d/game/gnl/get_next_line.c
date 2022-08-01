/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:55:14 by ple-berr          #+#    #+#             */
/*   Updated: 2021/11/29 11:07:56 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *str)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(str, '\n') == 0 && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_cut_line(char *str)
{
	char	*cut_line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	cut_line = malloc(i + 2);
	if (cut_line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cut_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		cut_line[i++] = '\n';
	cut_line[i] = '\0';
	return (cut_line);
}

char	*ft_leftovers(char *str)
{
	int		i;
	int		j;
	char	*left_overs;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	left_overs = malloc(ft_strlen(str) - i + 1);
	if (left_overs == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		left_overs[j++] = str[i++];
	left_overs[j] = '\0';
	free(str);
	return (left_overs);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read_buffer(fd, str);
	if (str == NULL)
		return (NULL);
	temp = ft_cut_line(str);
	if (!str)
		return (temp);
	str = ft_leftovers(str);
	return (temp);
}
