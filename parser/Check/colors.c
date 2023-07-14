/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 03:41:32 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:36:59 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	colors(t_data *data)
{
	int		i;
	char	**split;

	i = 0;
	while (data->map->file[i] != NULL)
	{
		split = ft_split(data->map->file[i], ", \n");
		if (split[0])
		{
			if (ft_strcmp(split[0], "F") == 0)
				rgb(&data->map->floor, split + 1);
			else if (ft_strcmp(split[0], "C") == 0)
				rgb(&data->map->ciel, split + 1);
		}
		free_splt(split);
		i++;
	}
	if (!is_valid_color(data->map->ciel))
		ft_error("Ciel color should be between 0 and 255");
	if (!is_valid_color(data->map->floor))
		ft_error("Floor color should be between 0 and 255");
}

int	is_valid_color(t_color color)
{
	return (color.r >= 0 && color.r <= 255 && \
		color.g >= 0 && color.g <= 255 && \
		color.b >= 0 && color.b <= 255);
}
