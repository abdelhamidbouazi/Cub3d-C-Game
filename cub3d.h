/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:34:29 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 01:28:29 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 960
#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
# include <math.h>
#include "stdio.h"
#include <unistd.h>


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

# define M_SPEED 14
# define M_ROTATE 5




int	map[24][24];

typedef struct s_player
{
	double x;
	double y;
	double angle;
	double fov;
}t_player;

typedef struct s_keys
{
	bool left;
	bool right;
	bool forward;
	bool back;
	bool rotate_left;
	bool rotate_right;
	bool esc;
	bool up;
	bool down;
}t_keys;

typedef struct s_ray{
	double f_x_v;
	double f_y_v;
	double f_x_h;
	double f_y_h;
	double distance;
	int		flag;

}t_ray;

typedef struct s_image
{
	void				*img_window;
	char				*add_img;
	int					*we;
	int					*so;
	int					*ea;
	int					*no;
	int					bit_pixel;
	int					line_len;
	int					endian;

}						t_image;


typedef struct s_data{

	void *mlx;
	void *win;
	char *no;
	char *so;
	char *ea;
	char *we;
	int wall_width;
	int wall_height;
	void *img;
	char *addr_img;
	int	bit_pixel;
	int	line_len;
	int	endian;
	t_player *player;
	t_keys *keys;
	t_ray *ray;
	t_image image;
	int check;
	bool check_texture;

}t_data;

void forward(t_data *data);
void back(t_data *data);
void left(t_data *data);
void right(t_data *data);
void rotate_left(t_data *data);
void rotate_right(t_data *data);
int esc();


// double raycasting_horizontal(t_data *data,double ray_angle);
// double raycasting_vertical(t_data *data, double ray_angle);

double	raycastingh(t_data *data, double ray_angle);
double	raycastingv(t_data *data, double ray_angle);
int	is_wall(t_data *data, double v_x, double v_y, int face);
double	distance(double xplayer, double xray, double yplayer, double yray);

#endif
