/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:44:13 by bleroy            #+#    #+#             */
/*   Updated: 2022/06/21 18:40:38 by bleroy           ###   ########.fr       */
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


# define SQUARE_SIZE 20
# define PI 3.14159265359
# define UP 13
# define ESCAPE 53
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define PURPLE 0x009900FF
# define PINK 0x00FF0099
# define GREEN 0x0099FF00
# define SQUARE 0x00003399

typedef struct s_raycasting
{
	double		x;
	double		y;
	double		delta_x;
	double		delta_y;
	double		angle;
	double		touch_y;
	double		touch_x;
}	t_raycasting;

typedef struct s_texture
{
	void	*n;
	void	*w;
	void	*s;
	void	*e;
	int		*floor;
	int		*ceiling;
}	t_texture;

typedef struct s_player
{
	char		direction;
}	t_player;

typedef struct s_images
{
	void	*img;
	int		*addr;
	int		bits;
	int		line;
	int		endian;
	int		pos_x;
	int		pos_y;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*file;
	char		**map;
	int			x;
	int			y;
	t_texture	text;
	t_player	player;
	t_images	images;
	t_raycasting	ray;
}	t_game;

//* **************** Game ****************
void	start(t_game *game);
int		keypressed(int key, t_game *game);
void	start_check_map(t_game *game);
int		closed(t_game *game);
void	draw_cube(t_game *game, int y, int x, int color);
void	draw_player(t_game *game, double delta_x, double delta_y);
void	draw_vector_x(t_game *game, double x, double y);
void	draw_vector_y(t_game *game, double x, double y);
int		move(int key, t_game *game);
void	put_color(t_game *game, int base_x, int base_y, int color);
void	draw_cube(t_game *game, int y, int x, int color);
void	print_map(t_game *game, int y, int x);
void	initray(t_game *game, t_raycasting *ray);
void	drawline(t_game *game, int player_x, int player_y, int endofX, int endofY);
void	raycast(t_game *game);
void	clearline(t_game *game, int player_x, int player_y, int endofX, int endofY);
void	clearcast(t_game *game);
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
void	check_wall(t_game *game);

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