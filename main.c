/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:32:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 09:11:42 by abouazi          ###   ########.fr       */
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
	if (!data.player)
		return 0;
	data.ray = (t_ray *)malloc(sizeof(t_ray));
	if (!data.ray)
		return 0;
	init_player(data.player);
	data.keys = (t_keys *)malloc(sizeof(t_keys));
	if (!data.keys)
		return 0;
	init_keys(data.keys);
	data.wall_width = WALL_WIDTH;
	data.wall_height = WALL_HEIGHT;

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

