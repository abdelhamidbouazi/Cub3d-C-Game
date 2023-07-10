/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:55:21 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:55:51 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*destination;

	if ((x >= 0 && x < SCREEN_WIDTH) && (y >= 0
			&& y < SCREEN_HEIGHT))
	{
		destination = (data->addr_img + (y * data->line_len + x
					* (data->bit_pixel / 8)));
		*(int *)destination = color;
	}
}
