/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:15:03 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:59:13 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_steps_vertical(t_data *data,double ray_angle, double *stepx, double *stepy)
{
	*stepx = WALL;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	{
		*stepx *= -1;
		data->check = -1;
	}
	*stepy = *stepx * tan(ray_angle);
	if (!(ray_angle > 0 && ray_angle < M_PI) && *stepy > 0)
		*stepy *= -1;
	if ((ray_angle > 0 && ray_angle < M_PI) && *stepy < 0)
		*stepy *= -1;
}

double	raycastingv(t_data *data, double ray_angle)
{
	double	stepx;
	double	stepy;

	data->check = 0;
	data->ray->f_x_v = floor(data->player->x / WALL) * WALL;
	if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
		data->ray->f_x_v += WALL;
	data->ray->f_y_v = data->player->y + (data->ray->f_x_v - data->player->x) * tan(ray_angle);
	init_steps_vertical(data,ray_angle,&stepx,&stepy);
	while (is_wall(data, data->ray->f_x_v, data->ray->f_y_v, 0))
	{
		data->ray->f_x_v += stepx;
		data->ray->f_y_v += stepy;
	}
	return (distance(data->player->x, data->ray->f_x_v, data->player->y,
			data->ray->f_y_v));
}
