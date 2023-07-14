/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:56:49 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:49:56 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall(t_data *data, int ray, double ciel_height, \
			double floor_height, double ray_angle)
{
	double	render_top;
	int		x;
	int		y;
	int		n;
	int		m;

	if (data->ray->flag == 1)
	{
		x = data->ray->f_x_v;
		y = data->ray->f_y_v;
	}
	else if (data->ray->flag == 0)
	{
		x = data->ray->f_x_h;
		y = data->ray->f_y_h;
	}
	n = 0;
	render_top = ciel_height;
	while (ciel_height <= floor_height)
	{
		m = 0;
		while (m < (floor_height - render_top) / WALL)
		{
			if (data->ray->flag == 0 && (ray_angle > 0 && \
				ray_angle < M_PI))
			{
				my_mlx_pixel_put(data, ray, (int)ciel_height \
				+ m, *(data->image.no + (int)(n * WALL) + \
				(int)fmod(x, WALL)));
			}
			else if (data->ray->flag == 1 && (ray_angle > M_PI / 2 && \
				ray_angle < 1.5 * M_PI))
			{
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, \
				*(data->image.so + (int)(n * WALL) + (int)fmod(y, WALL)));
			}
			if (data->ray->flag == 0 && (ray_angle > M_PI && \
				ray_angle < 2 * M_PI))
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, \
				*(data->image.ea + (int)(n * WALL) + (int)fmod(x, WALL)));
			else if (data->ray->flag == 1 && !(ray_angle > M_PI / 2 && \
				ray_angle < 1.5 * M_PI))
				my_mlx_pixel_put(data, ray, (int)ciel_height + m, \
				*(data->image.we + (int)(n * WALL) + (int)fmod(y, WALL)));
			m++;
		}
		n++;
		ciel_height += (floor_height - render_top) / WALL;
	}
}
