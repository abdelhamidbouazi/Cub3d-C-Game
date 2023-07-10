/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:40:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 07:40:30 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void parser(char **arg, t_map *map)
{
	if (extension(arg[1]))
		ft_error("Check File Name !");
	map->fd = open(arg[1], O_RDONLY);
	if (map->fd == -1)
	{
		close(map->fd);
		ft_error("Opening file error !");
	}
	map->map = read_map(arg);
	elements(map->map);
	textures(map);
	colors(map);
}

