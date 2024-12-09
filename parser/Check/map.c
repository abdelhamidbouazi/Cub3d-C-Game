/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:14:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 05:51:16 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_map(char **map)
{
	int	row;
	int	col;
	int	found;

	row = 0;
	found = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!found_char(map[row][col], " 01NSEW"))
				ft_error("Invalid character found in map.\n");
			if (found_char(map[row][col], "NSEW"))
				found++;
			col++;
		}
		row++;
	}
	if (!found)
		ft_error("Player not found!.\n");
	else if (found > 1)
		ft_error("This is not a multiplayer game..\n");
}
