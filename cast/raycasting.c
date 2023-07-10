/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:34:59 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:35:10 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
