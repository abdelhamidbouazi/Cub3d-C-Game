/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:41:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/08 03:00:33 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void forward(t_data *data)
{
	int x = (data->player->x + (cos(data->player->angle) * M_SPEED)) / 40;
	int y = (data->player->y + (sin(data->player->angle) * M_SPEED)) / 40;
	if(map[y][x] != 1)
	{
		 data->player->x +=  (cos(data->player->angle) * M_SPEED);
		 data->player->y +=  (sin(data->player->angle) * M_SPEED);
	}
}
