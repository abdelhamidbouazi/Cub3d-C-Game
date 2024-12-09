/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:41:30 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/17 05:59:01 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	assign_texture(char *key, char *value, t_map *map)
{
	if (ft_strcmp(key, "NO") == 0)
	{
		if (map->no)
			ft_error("Duplicated Texture");
		map->no = ft_strdup(value);
	}
	else if (ft_strcmp(key, "SO") == 0)
	{
		if (map->so)
			ft_error("Duplicated Texture");
		map->so = ft_strdup(value);
	}
	else if (ft_strcmp(key, "EA") == 0)
	{
		if (map->ea)
			ft_error("Duplicated Texture");
		map->ea = ft_strdup(value);
	}
	else if (ft_strcmp(key, "WE") == 0)
	{
		if (map->we)
			ft_error("Duplicated Texture");
		map->we = ft_strdup(value);
	}
}
