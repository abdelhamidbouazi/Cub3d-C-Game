/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:42:48 by abouazi           #+#    #+#             */
/*   Updated: 2023/07/16 13:58:35 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	press(int key, t_data *data)
{
	if (key == FORWARD)
		data->keys->forward = true;
	else if (key == BACK)
		data->keys->back = true;
	else if (key == LEFT)
		data->keys->left = true;
	else if (key == RIGHT)
		data->keys->right = true;
	else if (key == ROTATE_LEFT)
		data->keys->rotate_left = true;
	else if (key == ROTATE_RIGHT)
		data->keys->rotate_right = true;
	else if (key == ESC)
		data->keys->esc = true;
	return (0);
}
