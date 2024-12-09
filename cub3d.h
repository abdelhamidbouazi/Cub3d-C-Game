/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:34:29 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 06:14:36 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1
# define WALL_WIDTH 40
# define WALL_HEIGHT 40
# define SCREEN_WIDTH 920
# define SCREEN_HEIGHT 920

# define FORWARD 13
# define BACK 1
# define LEFT 0
# define RIGHT 2
# define ROTATE_RIGHT 124
# define UP 291
# define DOWN 293
# define ROTATE_LEFT 123
# define ESC 53
# define WALL 40

# define M_SPEED 8
# define M_ROTATE 3

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
}	t_key;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map {
	char	**map;
	int		fd;
	char	**file;
	int		i;
	char	*tmp;
	int		line;
	char	*tmp2;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		col;
	int		row;
	char	view_direction;
	t_color	floor;
	t_color	ciel;
}	t_map;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	double	x;
	double	y;
	double	angle;
	double	fov;
}	t_player;

typedef struct s_keys
{
	bool	left;
	bool	right;
	bool	forward;
	bool	back;
	bool	rotate_left;
	bool	rotate_right;
	bool	esc;
	bool	up;
	bool	down;
}	t_keys;

typedef struct s_ray{
	double	f_x_v;
	double	f_y_v;
	double	f_x_h;
	double	f_y_h;
	double	distance;
	int		flag;

}	t_ray;

typedef struct s_image
{
	void	*img_window;
	char	*add_img;
	int		*we;
	int		*so;
	int		*ea;
	int		*no;
	int		bit_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_draw
{
	double	project_plane;
	double	stripe_height;
	double	ciel_height;
	double	floor_height;
}	t_draw;

typedef struct s_data{
	void		*mlx;
	void		*win;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			wall_width;
	int			wall_height;
	void		*img;
	char		*addr_img;
	int			bit_pixel;
	int			line_len;
	int			endian;
	int			check;
	bool		check_texture;
	double		ray_angle;
	t_player	player;
	t_keys		*keys;
	t_ray		*ray;
	t_image		image;
	t_map		*map;
	t_draw		draw;
}	t_data;

// Parsing
void	parser(char **arg, t_data *data);
// Check
void	colors(t_data *game);
int		is_valid_color(t_color color);
void	elements(char **map);
int		extension(char *arg);
void	floor_ciel(char **map, int *index);
void	headers(char **map, int *index);
int		is_texture_missing(const char *texture_path);
// Fill
void	rgb(t_color *color, char **str);
void	textures(t_data *data);
void	map(t_data *data);
void	player(t_data *data);
void	assign_texture(char *key, char *value, t_map *map);
// Read
char	**read_map(char	**av);
int		num_of_lines(char **av);
char	**read_map(char	**av);
// Utils
void	free_splt(char **tab);
int		found_char(char c, char *set);
// utils
void	ft_error(char *err);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup2(char *str, int *i, char *s);
char	*ft_strndup(char *s1, int n);
int		ft_atoi(const char *str);
char	**ft_split(char *str, char *s);
char	*ft_strndup(char *s1, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// Get Next Line
char	*ft_read(char *leftxt, int fd);
char	*ft_get_line(char	*leftxt);
char	*ft_stock(char *leftxt);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
// events
int		move(t_data *data);
void	init_keys(t_keys *keys);
int		press(int key, t_data *data);
int		release(int key, t_data *data);
void	forward(t_data *data);
void	back(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
int		esc(t_data *data);
// cast
void	raycasting(t_data *data);
double	raycastingh(t_data *data, double ray_angle);
double	raycastingv(t_data *data, double ray_angle);
int		is_wall(t_data *data, double v_x, double v_y, int face);
double	distance(double xplayer, double xray, double yplayer, double yray);
void	create_img(t_data *data);
double	normalize_angle(double angle);
// render
void	draw3d(t_data *data, double ray_distance, double ray_angle, int ray);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	wall(t_data *data, int ray, double ciel_height, \
			double floor_height);
void	texture_so_and_ea(t_data *data);
void	texture_no_and_we(t_data *data);
void	ft_free(t_data *data);
void	get_texture(char *line, t_map *map);
char	*ft_trim(char *str);
void	init_texture_color(t_data *data);
int		split_func(char *color, int i, int *c, int *count);
int		valid_color_str(char *color);
int		is_player(char p);
int		check_surr2(char **line, int i, int j);
int		check_surr(char **line, int row);
#endif
