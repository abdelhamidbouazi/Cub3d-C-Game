/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:32:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/11 00:00:18 by abouazi          ###   ########.fr       */
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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void ft_free(t_data *data)
{
	free(data->map);
	free(data->player);
	free(data->ray);
	free(data->keys);
}



void draw_square(t_data *data, int x_start, int y_start,int color)
{
	for(int x  = 0 ; x < 4 ; x++)
	{
		for(int y  = 0 ; y < 4 ; y++)
		{
			my_mlx_pixel_put(data, x_start + x,y_start + y,color);
		}
	}
}
void draw_map(t_data *data)
{
	for(int y = 0; y < 24; y++)
	{
		for(int x = 0; x < 24; x++)
		{
			if(map[y][x] == 1)
				draw_square(data,x * 4 ,y * 4,255);
		}
	}
}
void draw_player(t_data *data)
{
	for(int x  = 1 ; x < 6 ; x++)
	{
		for(int y  = 1 ; y < 6 ; y++)
		{
			my_mlx_pixel_put(data,(data->player->x + x)/10,(data->player->y + y)/10 ,0xffffff);
		}
	}
}

void init_player(t_player *player)
{
	player->angle = 0;
	player->x = 41;
	player->y = 41;
	player->fov = M_PI / 3;
}

int main(int ac, char **av)
{
	t_data data;

	data.map = (t_map *)malloc(sizeof(t_map));
	if (!data.map)
		return 0;
	if(ac != 2)
		ft_error("Arguments Number Error!");
	parser(av, data.map);

	data.player = (t_player *)malloc(sizeof(t_player));
	if (data.player == NULL)
		return 0;
	data.ray = (t_ray *)malloc(sizeof(t_ray));
	if (data.ray == NULL)
		return 0;
	init_player(data.player);
	data.keys = (t_keys *)malloc(sizeof(t_keys));
	if (data.keys == NULL)
		return 0;
	init_keys(data.keys);
	data.wall_width = WALL_WIDTH;
	data.wall_height = WALL_HEIGHT;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	mlx_hook(data.win, 2, 0L, press, &data);
	mlx_hook(data.win, 3, 0L, release, &data);
	mlx_hook(data.win, 17, 1L, esc,NULL);
	texture(&data);
	raycasting(&data);
	mlx_loop_hook(data.mlx,move,&data);
	draw_map(&data);
	draw_player(&data);
	mlx_loop(data.mlx);
	ft_free(&data);
}

