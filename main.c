/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:32:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:13:33 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[24][24] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
};


// void draw_square(t_data *data, int x_start, int y_start,int color)
// {
// 	for(int x  = 0 ; x < 40 ; x++)
// 	{
// 		for(int y  = 0 ; y < 40 ; y++)
// 		{
// 			// mlx_pixel_put(data->mlx,data->win,x_start + x,y_start + y,color);
// 		}
// 	}
// }
// void draw_map(t_data *data)
// {
// 	for(int y = 0; y < 24; y++)
// 	{
// 		for(int x = 0; x < 24; x++)
// 		{
// 			if(map[y][x] == 1)
// 				draw_square(data,x * 40 ,y * 40,255);
// 		}
// 	}
// }
// void draw_player(t_data *data)
// {
// 	for(int x  = 0 ; x < 10 ; x++)
// 	{
// 		for(int y  = 0 ; y < 10 ; y++)
// 		{
// 			// mlx_pixel_put(data->mlx,data->win,data->player->x + x,data->player->y + y,0xffffff);
// 		}
// 	}
// }

// void drawRay(t_data *data, double X0, double Y0, double X1, double Y1, double angle, int scale,int color)
// {
//     X1 += cos(angle) * scale;
//     Y1 += sin(angle) * scale;

//     double dx = X1 - X0;
//     double dy = Y1 - Y0;

//     double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
//     double Xinc = dx / (double)steps;
//     double Yinc = dy / (double)steps;
//     for (int i = 0; i <= steps; i++)
//     {
//         // mlx_pixel_put(data->mlx, data->win, round(X0), round(Y0), color);
//         X0 += Xinc;
//         Y0 += Yinc;
//     }
// }


void init_player(t_player *player)
{
	player->angle = 0;
	player->x = 41;
	player->y = 41;
	player->fov = M_PI / 3;
}
void init_keys(t_keys *keys)
{
	keys->right = false;
	keys->left = false;
	keys->back = false;
	keys->forward = false;
	keys->rotate_left = false;
	keys->rotate_right = false;
	keys->esc = false;
	keys->up = false;
	keys->down = false;
}

int press(int key, t_data *data)
{
	if(key == FORWARD)
		data->keys->forward = true;
	else if(key == BACK)
		data->keys->back = true;
	else if(key == LEFT)
		data->keys->left = true;
	else if(key == RIGHT)
		data->keys->right = true;
	else if(key == ROTATE_LEFT)
		data->keys->rotate_left = true;
	else if(key == ROTATE_RIGHT)
		data->keys->rotate_right = true;
	else if(key == ESC)
		data->keys->esc = true;
	return 0;
}

int release(int key, t_data *data)
{
	if(key == FORWARD)
		data->keys->forward = false;
	else if(key == BACK)
		data->keys->back = false;
	else if(key == LEFT)
		data->keys->left = false;
	else if(key == RIGHT)
		data->keys->right = false;
	else if(key == ROTATE_LEFT)
		data->keys->rotate_left = false;
	else if(key == ROTATE_RIGHT)
		data->keys->rotate_right = false;
	else if(key == ESC)
		data->keys->esc = false;
	// else if(key == UP)
	// 	keys->up = false;
	// else if(key == DOWN)
	// 	keys->down = false;
	return 0;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}



void	create_img(t_data *data)
{
	data->line_len = 24;
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	data->addr_img = mlx_get_data_addr(data->img,
			&data->bit_pixel, &data->line_len, &data->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*destination;

	if ((x >= 0 && x < SCREEN_WIDTH) && (y >= 0
			&& y < SCREEN_HEIGHT))
	{
		destination = (data->addr_img + (y * data->line_len + x
					* (data->bit_pixel / 8)));
		*(int *)destination = color;
	}
}


void texture(t_data *data)
{
	int	h;
	int	w;
	// (void)data;
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/so.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.so = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel, &data->image.line_len, &data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/ea.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.no = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx, "xpm/no.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.we = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);
	data->image.img_window = mlx_xpm_file_to_image(data->mlx,"xpm/we.xpm", &w, &h);
	if (!data->image.img_window)
		exit(0);
	data->image.ea = (int *)mlx_get_data_addr(data->image.img_window,
			&data->image.bit_pixel,
			&data->image.line_len,
			&data->image.endian);

}
void	wall(t_data *data, int ray,double ciel_height, double floor_height,double ray_angle)
{
	double	render_top;
	// texture(data);
	int x,y;
	if(data->ray->flag == 1)
	{
		x= data->ray->f_x_v;
		y= data->ray->f_y_v;
	}
	else if( data->ray->flag == 0)
	{
		x= data->ray->f_x_h;
		y= data->ray->f_y_h;
	}

	int n = 0;
	render_top = ciel_height;
	(void)ray_angle;
	while (ciel_height <= floor_height)
	{
		int m = 0;
		while (m < (floor_height- render_top)/ WALL)
		{

			if (data->ray->flag == 0 && (ray_angle > 0 && ray_angle < M_PI))
			{
					my_mlx_pixel_put(data, ray, (int)ciel_height + m, *(data->image.no
						+ (int)(n * WALL) + (int)fmod(x, WALL)));
			}
			else if (data->ray->flag == 1 && (ray_angle > M_PI / 2 && ray_angle <  1.5 * M_PI))
			{
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, *(data->image.so
						+ (int)(n * WALL) + (int)fmod(y, WALL)));
			}
			if (data->ray->flag == 0 && (ray_angle > M_PI && ray_angle <  2*M_PI))
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, *(data->image.ea
						+ (int)(n * WALL) + (int)fmod(x, WALL)));
			else if (data->ray->flag == 1 && !(ray_angle > M_PI / 2 && ray_angle <  1.5 * M_PI))
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, *(data->image.we
						+ (int)(n * WALL) + (int)fmod(y, WALL)));
			m++;
		}
		n++;
		// my_mlx_pixel_put(data, ray, (int)ciel_height , 0x0fff00);
		ciel_height += (floor_height - render_top) / WALL;
	}
}

void draw3D(t_data *data,double ray_distance,double ray_angle ,int ray)
{
	double project_plane = (SCREEN_WIDTH / 2 ) / tan(data->player->fov/2);
	ray_distance *=  cos(ray_angle - data->player->angle);
	double stripe_height = WALL / ray_distance * project_plane;
	double ciel_height = (SCREEN_HEIGHT / 2) - (stripe_height / 2);
	double floor_height = (SCREEN_HEIGHT / 2) + (stripe_height / 2);

	int i = 0;
	while(i < ciel_height)
	{
		my_mlx_pixel_put(data, ray, i, 0x045B5B);
		i++;
	}
	wall(data,ray,ciel_height,floor_height,ray_angle);
	while(floor_height < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data, ray, floor_height , 0x484848);
		floor_height++;
	}
}

void raycasting(t_data *data)
{
	create_img(data);
	int number_rays = SCREEN_WIDTH;
	double ray_angle = data->player->angle - (data->player->fov / 2);
	int i = 0;
	while(i < number_rays)
	{
		//ray_angle = data->player->angle;
		ray_angle = normalize_angle(ray_angle);
		double dish = raycastingh(data,ray_angle);
		double disv = raycastingv(data,ray_angle);

		if (dish > disv)
		{
			data->ray->flag = 1;
			// drawRay(data,data->player->x,data->player->y,data->player->x,data->player->y,ray_angle,disv,0x00ff00);
			draw3D(data,disv,ray_angle,i);
		}
		else
		{
			data->ray->flag = 0;
			// drawRay(data,data->player->x,data->player->y,data->player->x,data->player->y,ray_angle,dish,0x00ff00);
			draw3D(data,dish,ray_angle,i);
		}
		ray_angle += (data->player->fov / number_rays);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0,
		0);
}


int move(t_data *data)
{
	if(data->keys->forward == true)
	{
		forward(data);
		raycasting(data);
	}
	if(data->keys->back == true)
	{
		back(data);
		raycasting(data);
	}
	if(data->keys->left == true)
	{
		left(data);
		raycasting(data);
	}
	if(data->keys->right == true)
	{
		right(data);
		raycasting(data);
	}
	if(data->keys->rotate_left == true)
	{
		rotate_left(data);
		raycasting(data);
	}
	if(data->keys->rotate_right == true)
	{
		rotate_right(data);
		raycasting(data);
	}
	if (data->keys->esc == true)
		esc();
	// mlx_clear_window(data->mlx,data->win);
	// draw_map(data);
	// draw_player(data);
	// drawRay(data,data->player->x,data->player->y,data->player->x,data->player->y,data->player->angle,M_SPEED * 50,0xff0000);
	return 0;
}

int main()
{
	t_data data;
	data.player = (t_player *)malloc(sizeof(t_player));
	data.ray = (t_ray *)malloc(sizeof(t_ray));
	init_player(data.player);
	data.keys = (t_keys *)malloc(sizeof(t_keys));
	init_keys(data.keys);
	data.wall_width = 40;
	data.wall_height = 40;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	// draw_map(&data);
	// draw_player(&data);
	mlx_hook(data.win, 2, 0L, press, &data);
	mlx_hook(data.win, 3, 0L, release, &data);
	mlx_hook(data.win, 17, 1L, esc,NULL);
	texture(&data);
	raycasting(&data);
	mlx_loop_hook(data.mlx,move,&data);
	mlx_loop(data.mlx);
}

