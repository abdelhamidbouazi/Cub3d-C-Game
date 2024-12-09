/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:54:08 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 15:19:28 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g
		<< 8 | b);
}

void	draw3d(t_data *data, double ray_distance, double ray_angle, int ray)
{
	int		i;

	data->ray_angle = ray_angle;
	ray_distance = ray_distance * cos(ray_angle - data->player.angle);
	data->draw.project_plane = (SCREEN_WIDTH / 2) / tan(data->player.fov / 2);
	data->draw.stripe_height = WALL / ray_distance * data->draw.project_plane;
	data->draw.ciel_height = (SCREEN_HEIGHT / 2) \
		- (data->draw.stripe_height / 2);
	data->draw.floor_height = (SCREEN_HEIGHT / 2) \
		+ (data->draw.stripe_height / 2);
	i = 0;
	ray_distance *= cos(ray_angle - data->player.angle);
	while (i++ < data->draw.ciel_height)
	{
		my_mlx_pixel_put(data, ray, i, color(data->map->ciel.r, \
		data->map->ciel.g, data->map->ciel.b));
	}
	wall(data, ray, data->draw.ciel_height, data->draw.floor_height);
	while (data->draw.floor_height < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data, ray, data->draw.floor_height, \
		color(data->map->floor.r, data->map->floor.g, data->map->floor.b));
		data->draw.floor_height++;
	}
}
