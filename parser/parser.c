/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:40:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/06/25 04:40:44 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void parser(char **arg, c_game *map)
{
	if (extension(arg[1]))
		ft_error("Check File Name !");
	map->map.fd = open(arg[1], O_RDONLY);
	if (map->map.fd == -1)
	{
		close(map->map.fd);
		ft_error("Opening file error !");
	}
	map->map.map = read_map(arg);
	elements(map->map.map);
	textures(map);
	colors(map);
}

