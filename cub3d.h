/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:44:13 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/08 17:53:49 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

typedef struct s_texture
{
	char	*n;
	char	*w;
	char	*s;
	char	*e;
	int		*floor;
	int		*ceiling;
}	t_texture;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}	t_player;

typedef struct s_game
{
	char		*file;
	char		**map;
	void		*win;
	void		*mlx;
	int			x;
	int			y;
	t_texture	text;
	t_player	player;
}	t_game;

//* **************** Parsing ****************
int		openmap(char **argv, t_game *game);
int		error(char *str);
void	get_texture(int len, t_game *game);
char	*get_texture_2(char *str);
void	get_texture3(char *str, t_game *game);
int		*get_color(char *str);
int		checkvalid(int len, t_game *game);
int		checkfile(t_game *game);
int		checkmap(int len, t_game *game);
int		checkstr(char *str);
int		checktab(char c);
void	getouttab(char **tab);
void	scale(t_game *game);
int		getmap(int fd);
void	parsing_map(t_game *game);
void	check_first_and_last(t_game *game);
void	valid_map(t_game *game);
void	get_player(t_game *game);

//* **************** Utils ****************
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		alpha(int c);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif