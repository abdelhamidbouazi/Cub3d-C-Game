/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:41:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/11 08:21:06 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward(t_data *data)
{
	int	x;
	int	y;

	x = (data->player->x + (cos(data->player->angle) * M_SPEED)) / 40;
	y = (data->player->y + (sin(data->player->angle) * M_SPEED)) / 40;
	if (map[y][x] != 1)
	{
		data->player->x += (cos(data->player->angle) * M_SPEED);
		data->player->y += (sin(data->player->angle) * M_SPEED);
	}
}
