/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:41:30 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 19:09:59 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	assign_texture(char *key, char *value, t_map *map)
{
	if (ft_strcmp(key, "NO") == 0)
		map->no = ft_strdup(value);
	else if (ft_strcmp(key, "SO") == 0)
		map->so = ft_strdup(value);
	else if (ft_strcmp(key, "EA") == 0)
		map->ea = ft_strdup(value);
	else if (ft_strcmp(key, "WE") == 0)
		map->we = ft_strdup(value);
}

void	textures(t_data *data)
{
	int		i;
	char	**split;

	i = 0;
	while (i < 4)
	{
		split = ft_split(data->map->file[i], ", \n");
		if (!split[0])
		{
			free_splt(split);
			return ;
		}
		assign_texture(split[0], split[1], data->map);
		free_splt(split);
		i++;
	}
	if (is_texture_missing(data->map->no) || \
		is_texture_missing(data->map->so) || \
		is_texture_missing(data->map->ea) || \
		is_texture_missing(data->map->we))
	{
		ft_error("Texture not found!!");
	}
}
