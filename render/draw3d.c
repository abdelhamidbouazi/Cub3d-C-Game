/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:54:08 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:40:36 by abouazi          ###   ########.fr       */
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
	double	project_plane;
	double	stripe_height;
	double	ciel_height;
	double	floor_height;
	int		i;

	project_plane = (SCREEN_WIDTH / 2) / tan(data->player->fov / 2);
	stripe_height = WALL / ray_distance * project_plane;
	ciel_height = (SCREEN_HEIGHT / 2) - (stripe_height / 2);
	floor_height = (SCREEN_HEIGHT / 2) + (stripe_height / 2);
	i = 0;
	ray_distance *= cos(ray_angle - data->player->angle);
	while (i++ < ciel_height)
	{
		my_mlx_pixel_put(data, ray, i, color(data->map->ciel.r, \
		data->map->ciel.g, data->map->ciel.b));
	}
	wall(data, ray, ciel_height, floor_height, ray_angle);
	while (floor_height < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data, ray, floor_height, \
		color(data->map->floor.r, data->map->floor.g, data->map->floor.b));
		floor_height++;
	}
}
