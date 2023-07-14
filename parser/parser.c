/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:40:51 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/14 17:14:27 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parser(char **arg, t_data *data)
{
	if (extension(arg[1]))
		ft_error("Check File Name !");
	data->map->fd = open(arg[1], O_RDONLY);
	if (data->map->fd == -1)
	{
		close(data->map->fd);
		ft_error("Opening file error !");
	}
	data->map->map = read_map(arg);
	elements(data->map->map);
	textures(data->map);
	colors(data->map);
}
