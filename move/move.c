/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:46:53 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/10 06:47:15 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int move(t_data *data)
{
	if(data->keys->forward == true)
	{
		forward(data);
		raycasting(data);
	}
	if(data->keys->back == true)
	{
		back(data);
		raycasting(data);
	}
	if(data->keys->left == true)
	{
		left(data);
		raycasting(data);
	}
	if(data->keys->right == true)
	{
		right(data);
		raycasting(data);
	}
	if(data->keys->rotate_left == true)
	{
		rotate_left(data);
		raycasting(data);
	}
	if(data->keys->rotate_right == true)
	{
		rotate_right(data);
		raycasting(data);
	}
	if (data->keys->esc == true)
		esc();
	// mlx_clear_window(data->mlx,data->win);
	// draw_map(data);
	// draw_player(data);
	// drawRay(data,data->player->x,data->player->y,data->player->x,data->player->y,data->player->angle,M_SPEED * 50,0xff0000);
	return 0;
}
