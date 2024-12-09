/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:50:08 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:50:47 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_img(t_data *data)
{
	data->line_len = data->map->row;
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	data->addr_img = mlx_get_data_addr(data->img,
			&data->bit_pixel, &data->line_len, &data->endian);
}
