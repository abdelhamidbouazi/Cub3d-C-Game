/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:36:02 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 14:23:50 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall(t_data *data, double v_x, double v_y, int face)
{
	int	y;
	int	x;

	if (face == 1)
		v_y += data->check;
	else
		v_x += data->check;
	if (v_x > data->map->col * WALL || v_y > data->map->row * WALL)
		return (0);
	if (floor(v_x / WALL) < 0 || floor(v_x / WALL) >= data->map->col \
		|| floor(v_y / WALL) < 0 || floor(v_y / WALL) >= data->map->row)
		return (0);
	y = floor(v_y / WALL);
	x = floor(v_x / WALL);
	if (x >= data->map->col || y >= data->map->row)
		return (0);
	if (data->map->map[y][x] == '1')
		return (0);
	return (1);
}
