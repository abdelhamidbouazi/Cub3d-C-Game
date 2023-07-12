/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:36:02 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/11 08:05:02 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall(t_data *data, double v_x, double v_y, int face)
{
	if (face == 1)
		v_y += data->check;
	else
		v_x += data->check;
	if (v_y > 24 * WALL || v_x > 24 * WALL)
		return (0);
	if (floor(v_x / WALL) < 0 || floor(v_x / WALL) >= 24 \
		|| floor(v_y / WALL) < 0 || floor(v_y / WALL) >= 24)
		return (0);
	if (map[(int)floor(v_y / WALL)][(int)floor(v_x / WALL)] == 1)
		return (0);
	return (1);
}
