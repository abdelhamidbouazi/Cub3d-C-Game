/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:04:01 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/15 02:10:44 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	player(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (in_charset(map->map[row][col], "NSEW"))
			{
				map->player.p_x = row;
				map->player.p_y = col;
				map->view_direction = map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}
