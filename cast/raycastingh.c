/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:15:05 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 02:48:43 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(double xplayer, double xray, double yplayer, double yray)
{
	double	result;
	double sum1;
	double sum2;

	sum1 = pow(xray - xplayer, 2);
	sum2 = pow(yray - yplayer, 2);
	result = sqrt(sum1 + sum2);
	return (result);
}

void init_steps_horizental(t_data *data,double ray_angle, double *stepx, double *stepy)
{
	*stepy = WALL;
	if (!(ray_angle > 0 && ray_angle < M_PI))
	{
		*stepy *= -1;
		data->check = -1;
	}
	*stepx = *stepy / tan(ray_angle);
	if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && *stepx < 0)
		*stepx *= -1;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && *stepx > 0)
		*stepx *= -1;
}

double	raycastingh(t_data *data, double ray_angle)
{
	double	stepx;
	double	stepy;

	data->check = 0;
	data->ray->f_y_h = floor(data->player->y / WALL ) * WALL;
	if ((ray_angle > 0 && ray_angle < M_PI))
		data->ray->f_y_h += WALL;
	data->ray->f_x_h = data->player->x + (data->ray->f_y_h - data->player->y) / tan(ray_angle);
	init_steps_horizental(data,ray_angle,&stepx,&stepy);
	while (is_wall(data, data->ray->f_x_h, data->ray->f_y_h, 1))
	{
		data->ray->f_x_h += stepx;
		data->ray->f_y_h += stepy;
	}
	return (distance(data->player->x, data->ray->f_x_h, data->player->y,
			 data->ray->f_y_h));
}
