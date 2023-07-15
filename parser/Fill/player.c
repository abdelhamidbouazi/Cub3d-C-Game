/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:04:01 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/15 02:29:36 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	player(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map->map[row])
	{
		col = 0;
		while (data->map->map[row][col])
		{
			if (in_charset(data->map->map[row][col], "NSEW"))
			{
				data->player->p_x = row;
				data->player->p_y = col;
				data->map->view_direction = data->map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}
