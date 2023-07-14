/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:41:30 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 18:37:08 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
		if (ft_strcmp(split[0], "NO") == 0)
			data->map->no = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "SO") == 0)
			data->map->so = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "EA") == 0)
			data->map->ea = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "WE") == 0)
			data->map->we = ft_strdup(split[1]);
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
