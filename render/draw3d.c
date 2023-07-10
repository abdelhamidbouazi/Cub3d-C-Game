/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:54:08 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:54:17 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
