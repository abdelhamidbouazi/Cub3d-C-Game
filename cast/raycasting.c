/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:34:59 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:36:17 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_data *data)
{
	int		number_rays;
	double	ray_angle;
	int		i;
	double	dish;
	double	disv;

	create_img(data);
	number_rays = SCREEN_WIDTH;
	ray_angle = data->player->angle - (data->player->fov / 2);
	i = 0;
	while (i < number_rays)
	{
		ray_angle = normalize_angle(ray_angle);
		dish = raycastingh(data, ray_angle);
		disv = raycastingv(data, ray_angle);
		if (dish > disv)
		{
			data->ray->flag = 1;
			draw3d(data, disv, ray_angle, i);
		}
		else
		{
			data->ray->flag = 0;
			draw3d(data, dish, ray_angle, i);
		}
		ray_angle += (data->player->fov / number_rays);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
