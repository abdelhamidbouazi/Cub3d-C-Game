/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:46:53 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 15:01:11 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_movement(t_data *data)
{
	if (data->keys->forward == true)
		forward(data);
	if (data->keys->back == true)
		back(data);
	if (data->keys->left == true)
		left(data);
	if (data->keys->right == true)
		right(data);
	if (data->keys->rotate_left == true)
		rotate_left(data);
	if (data->keys->rotate_right == true)
		rotate_right(data);
	if (data->keys->esc == true)
		esc(data);
}

void	update_display(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	raycasting(data);
}

int	move(t_data *data)
{
	handle_movement(data);
	update_display(data);
	return (0);
}
