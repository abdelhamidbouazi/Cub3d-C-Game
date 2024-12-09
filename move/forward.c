/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:41:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 14:24:45 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward(t_data *data)
{
	int	x;
	int	y;

	x = (data->player.x + (cos(data->player.angle) * M_SPEED)) / WALL;
	y = (data->player.y + (sin(data->player.angle) * M_SPEED)) / WALL;
	if (data->map->map[y][x] != '1')
	{
		data->player.x += (cos(data->player.angle) * M_SPEED);
		data->player.y += (sin(data->player.angle) * M_SPEED);
	}
}
