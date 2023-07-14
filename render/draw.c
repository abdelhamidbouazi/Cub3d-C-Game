/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:20:32 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:32:21 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_data *data, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x++ < 4)
	{
		y = 0;
		while (y++ < 4)
			my_mlx_pixel_put(data, x_start + x, y_start + y, color);
	}
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y++ < 24)
	{
		x = 0;
		while (x < 24)
		{
			if (map[y][x] == 1)
				draw_square(data, x * 4, y * 4, 255);
		}
	}
}

void	draw_player(t_data *data)
{
	int	y;
	int	x;

	x = 1;
	while (x++ < 6)
	{
		y = 1;
		while (y++ < 6)
			my_mlx_pixel_put(data, (data->player->x + x) / 10, \
			(data->player->y + y) / 10, 0xffffff);
	}
}
