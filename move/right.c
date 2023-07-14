/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:32:52 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:12:46 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	right(t_data *data)
{
	int	x;
	int	y;

	x = (data->player->x - M_SPEED * cos(data->player->angle - (M_PI
					/ 2))) / 40;
	y = (data->player->y - M_SPEED * sin(data->player->angle - (M_PI
					/ 2))) / 40;
	if (map[y][x] != 1)
	{
		data->player->x -= M_SPEED * cos(data->player->angle - (M_PI
					/ 2));
		data->player->y -= M_SPEED * sin(data->player->angle - (M_PI
					/ 2));
	}
}
