/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <ple-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:44:13 by bleroy            #+#    #+#             */
/*   Updated: 2022/07/13 10:36:46 by ple-berr         ###   ########.fr       */
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
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define ESCAPE 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define PURPLE 0x009900FF
# define PINK 0x00FF0099
# define GREEN 0x0099FF00
# define SQR 0x00003399
# define WIDTH 640
# define HEIGHT 480

typedef struct s_raycasting
{
	double		x;
	double		y;
	double		delta_x;
	double		delta_y;
	double		angle;
	double		plane_x;
	double		plane_y;
	double		touch_y;
	double		touch_x;
	int			map_x;
	int			map_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		dir_x;
	double		dir_y;
	int			color;
	int			ceiling;
	int			floor;
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
	void			*mlx;
	void			*win;
	char			*file;
	char			**map;
	int				x;
	int				y;
	t_texture		text;
	t_player		player;
	t_images		img;
	t_raycasting	ray;
}	t_game;

//* **************** Game ****************
void	start(t_game *game);
int		closed(t_game *game);
void	draw_cube(t_game *game, int y, int x, int color);
void	put_color(t_game *game, int base_x, int base_y, int color);
void	draw_player(t_game *game);
void	draw_vector_x(t_game *game, double x, double y);
void	draw_vector_y(t_game *game, double x, double y);
void	start_check_map(t_game *game);
int		keypressed(int key, t_game *game);
int		move(int key, t_game *game);
void	clear_player(t_game *game);
void	draw_cube(t_game *game, int y, int x, int color);
void	print_map(t_game *game, int y, int x);
void	clearcast(t_game *game);
void	drawline(t_game	*game, int x, int draw_start, int draw_end);
void	initray(t_game *game, t_raycasting *ray);
void	raycast(t_game *game);
double	define_delta(double rayDir);
double	define_dist(double rayDir, double ray, double map, double deltaDist);
double	define_step(double rayDir);
int		init_struct(t_game *g, int x);

void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	rotate_left(t_game *g);
void	rotate_right(t_game *g);
void	rotate_direction(t_game *g);

//* **************** Parsing ****************
int		openmap(char **argv, t_game *game);
int		error(char *str);
void	get_texture(int len, t_game *game);
int		rgb_to_hex(t_game *game);
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