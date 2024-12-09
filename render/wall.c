/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:56:49 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 15:45:42 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	assign_values(t_data *data, int *x, int *y, int *n)
{
	if (data->ray->flag == 1)
	{
		*x = data->ray->f_x_v;
		*y = data->ray->f_y_v;
	}
	else if (data->ray->flag == 0)
	{
		*x = data->ray->f_x_h;
		*y = data->ray->f_y_h;
	}
	*n = 0;
}

typedef struct s_texture{
	int		x;
	int		y;
	int		n;
	int		m;
	int		ray;
}t_texture;

void	render_texture(t_data *data, t_texture *texture, double ciel_height)
{
	if (data->ray->flag == 0 && (data->ray_angle > 0 && \
				data->ray_angle < M_PI))
	{
		my_mlx_pixel_put(data, texture->ray, (int)ciel_height \
		+ texture->m, *(data->image.no + (int)(texture->n * WALL) + \
		(int)fmod(texture->x, WALL)));
	}
	else if (data->ray->flag == 1 && (data->ray_angle > M_PI / 2 && \
		data->ray_angle < 1.5 * M_PI))
	{
		my_mlx_pixel_put(data, texture->ray, (int)ciel_height + texture->m, \
		*(data->image.so + (int)(texture->n * \
		WALL) + (int)fmod(texture->y, WALL)));
	}
	if (data->ray->flag == 0 && (data->ray_angle > M_PI && \
		data->ray_angle < 2 * M_PI))
		my_mlx_pixel_put(data, texture->ray, (int)ciel_height + texture->m, \
		*(data->image.ea + (int)(texture->n * \
		WALL) + (int)fmod(texture->x, WALL)));
	else if (data->ray->flag == 1 && !(data->ray_angle > M_PI / 2 && \
		data->ray_angle < 1.5 * M_PI))
		my_mlx_pixel_put(data, texture->ray, (int)ciel_height + texture->m, \
		*(data->image.we + (int)(texture->n * \
		WALL) + (int)fmod(texture->y, WALL)));
}

void	wall(t_data *data, int ray, double ciel_height, \
			double floor_height)
{
	double		render_top;
	t_texture	texture;

	texture.ray = ray;
	assign_values(data, &texture.x, &texture.y, &texture.n);
	render_top = ciel_height;
	while (ciel_height <= floor_height)
	{
		texture.m = 0;
		while (texture.m < (floor_height - render_top) / WALL)
		{
			render_texture(data, &texture, ciel_height);
			texture.m++;
		}
		texture.n++;
		ciel_height += (floor_height - render_top) / WALL;
	}
}
